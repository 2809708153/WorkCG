#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string res = "";
    res += s[0];
    int i, count = 1;
    for (i = 1; i < (int)s.length(); i++) {
        if (s[i] == s[i - 1])
            count++;
        else {
            if (count != 1)
                res += to_string(count);
            res += s[i];
            count = 1;
        }
    }
    cout << res;
    return 0;
}