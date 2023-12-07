#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000], sum = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    //大于四人时，贪心取最优
    //1、最快的人把最慢的两个人分别运过去再回来，耗时T[n] + T[1] + T[n - 1] + T[1]
    //2、最快和次快的人先过去，其中一个回来，最慢的两个一起过去，另一个再把瓶子带回来，耗时T[2] + T[2] + T[n] + T[1]
    while (n >= 4) {
        sum += min(a[1] * 2 + a[n] + a[n - 1], a[2] * 2 + a[1] + a[n]);
        n -= 2;
    }
    //少于4个人时
    if (n == 3)
        sum += a[1] + a[2] + a[3];   //两个带一个让二者时间少的回去，即三者相加
    else if (n == 2)
        sum += a[2];
    else if (n == 1)
        sum += a[1];
    cout << sum << endl;
    return 0;
}