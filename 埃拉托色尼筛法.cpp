#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define Max 2000000
int prime[Max], vist[Max] = { 0 };
int k = 0;
void Era(int n) {
    int i;
    long long j;
    for (i = 2; i <= n; i++) {
        if (!vist[i]) {
            prime[k++] = i;
            for (j = 1ll * i * i; j <= n; j += i)   //1ll²»¿ÉÊ¡ÂÔ
                vist[j] = 1;
        }
    }
}
int main() {
    int i, n;
    cin >> n;
    Era(n);
    for (i = 0; i < k; i++)
        cout << prime[i] << " ";
    return 0;
}