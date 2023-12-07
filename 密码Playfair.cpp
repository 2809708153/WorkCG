#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string in, t, str = "";    //分别是控制输入，文件输入，文件输出以及中间字符串 
    char s[5][5];  //二维数组存储密码表
    int num[26] = {0};   //字母映射表
    int i, j, k = 0;
    cin >> in;
    ifstream fin("encrypt.txt");
    getline(fin, t);
    for (i = 0; i < (int)in.length(); i++) {     //将字符串中去重按顺序加入到str中
        num[in[i] - 'A']++;
        if (in[i] == 'I' && num[9] != 0)       //当含有J时I跳过
            continue;
        if (in[i] == 'J' && num[8] != 0)       //当含有I时J跳过
            continue;
        if (num[in[i] - 'A'] == 1)    //不含有字符时添加
            str += in[i];
    }
    for (i = 0; i < 26; i++) {
        if (i == 8 && num[9] != 0)      //当含有J时I跳过
            continue;
        if (i == 9 && num[8] != 0)      //当含有I时J跳过
            continue;
        if (num[i] == 0) {
            str += char(i + 'A');       //添加未出现的
            num[i]++;      //防止I和J都添加
        }
    }
    int a1 = -1, a2 = -2, b1 = -3, b2 = -4;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            s[i][j] = str[k++];
            if (s[i][j] == t[0]) {    //记录两个字符位置
                a1 = i;
                b1 = j;
            }
            if (s[i][j] == t[1]) {
                a2 = i;
                b2 = j;
            }
        }
    ofstream fout("output.txt");
    string res = "";
    if (a1 == a2 || b1 == b2) {      //同一行或同一列
        res += t[1];
        res += t[0];

    }
    else {
        res += s[a1][b2];       //形成矩阵，交换下标即可
        res += s[a2][b1];
    }
    fout << res;
    fout.close();
    return 0;
}