#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    string in, t, str = "";    //�ֱ��ǿ������룬�ļ����룬�ļ�����Լ��м��ַ��� 
    char s[5][5];  //��ά����洢�����
    int num[26] = {0};   //��ĸӳ���
    int i, j, k = 0;
    cin >> in;
    ifstream fin("encrypt.txt");
    getline(fin, t);
    for (i = 0; i < (int)in.length(); i++) {     //���ַ�����ȥ�ذ�˳����뵽str��
        num[in[i] - 'A']++;
        if (in[i] == 'I' && num[9] != 0)       //������JʱI����
            continue;
        if (in[i] == 'J' && num[8] != 0)       //������IʱJ����
            continue;
        if (num[in[i] - 'A'] == 1)    //�������ַ�ʱ���
            str += in[i];
    }
    for (i = 0; i < 26; i++) {
        if (i == 8 && num[9] != 0)      //������JʱI����
            continue;
        if (i == 9 && num[8] != 0)      //������IʱJ����
            continue;
        if (num[i] == 0) {
            str += char(i + 'A');       //���δ���ֵ�
            num[i]++;      //��ֹI��J�����
        }
    }
    int a1 = -1, a2 = -2, b1 = -3, b2 = -4;
    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++) {
            s[i][j] = str[k++];
            if (s[i][j] == t[0]) {    //��¼�����ַ�λ��
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
    if (a1 == a2 || b1 == b2) {      //ͬһ�л�ͬһ��
        res += t[1];
        res += t[0];

    }
    else {
        res += s[a1][b2];       //�γɾ��󣬽����±꼴��
        res += s[a2][b1];
    }
    fout << res;
    fout.close();
    return 0;
}