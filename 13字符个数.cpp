#include <bits/stdc++.h>
using namespace std;


int main() {
    char s[100];
    int num[1000] = { 0 };
    cin >> s;
    int i, count = 0;
    for (i = 0; i < (int)strlen(s); i++) {
        if (num[int(s[i])] == 0)
            count++;
        num[int(s[i])]++;
    }
    cout << "s:" << s << endl;
    cout << "Total number of characters:" << count << endl;
    for (i = 0; i < 1000; i++)
        if (num[i] > 0)
            cout << char(i) << ":" << num[i] << "  ";
    return 0;
}