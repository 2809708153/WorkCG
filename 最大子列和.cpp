#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[100000];
    int n, i;
    cin >> n;
    for (i = 0; i < n;i++)
        cin >> arr[i];
    int len = i, res = 0, sum = 0;
    for (i = 0; i < len; i++) {
        sum += arr[i];
        if (sum > res && sum > 0)
            res = sum;
        if (sum < 0)
            sum = 0;
    }
    cout << res;
    return 0;
}