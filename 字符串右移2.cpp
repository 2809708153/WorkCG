#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; 
    int n; 
    cin >> s >> n;
    cout << s.substr(s.size() - n,s.size()) + s.substr(0,s.size()-n);
    return 0;
}



/* ����
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void RMove(char* str, int n) {
    int i, len = strlen(str), j;
    for (i = 0; i < n; i++) {
        char t = str[len - 1];
        for (j = len - 1; j > 0; j--)
            str[j] = str[j - 1];
        str[0] = t;
    }
}
int main() {
    char s[100];
    int n;
    cin >> s;
    cin >> n;
    RMove(s, n);
    cout << s;
    return 0;
}*/