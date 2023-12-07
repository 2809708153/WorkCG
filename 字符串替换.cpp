#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(){
    string in, out;
    cout << "input the string want to be replaced:" << endl;
    cin >> in;
    cout << "input the string replace the initial one:" << endl;
    cin >> out;
    string str, s = "", t;
    ifstream fin("filein.txt");
    while (getline(fin, str)){
        for (unsigned int i = 0; i < str.length(); i++){
            t = str.substr(i, (int)in.length());
            transform(t.begin(), t.end(), t.begin(), ::tolower);  //转换为小写
            transform(in.begin(), in.end(), in.begin(), ::tolower);
            if ( t== in){
                s += out;
                i += (int)in.length() - 1;  //满足条件索引跳跃
            }
            else
                s += str[i];
        }
        s += "\n";
    }
    fin.close();
    ofstream fout("fileout.txt");
    fout << s;
    fout.close();
    return 0;
}