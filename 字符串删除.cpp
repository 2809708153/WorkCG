#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, res = "";
    cin >> a >> b;
    int i, j;
    int l1 = a.length(), l2 = b.length();
    for (i = 0; i < l1; i++) {
        int flag = 1;
        for (j = 0; j < l2; j++) 
            if (b[j] == a[i]) {
                flag = 0;
                break;
            }  
        if (flag)
            res += a[i];
    }
    cout << res;
    return 0;
}