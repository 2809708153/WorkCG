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
    //��������ʱ��̰��ȡ����
    //1�������˰������������˷ֱ��˹�ȥ�ٻ�������ʱT[n] + T[1] + T[n - 1] + T[1]
    //2�����ʹο�����ȹ�ȥ������һ������������������һ���ȥ����һ���ٰ�ƿ�Ӵ���������ʱT[2] + T[2] + T[n] + T[1]
    while (n >= 4) {
        sum += min(a[1] * 2 + a[n] + a[n - 1], a[2] * 2 + a[1] + a[n]);
        n -= 2;
    }
    //����4����ʱ
    if (n == 3)
        sum += a[1] + a[2] + a[3];   //������һ���ö���ʱ���ٵĻ�ȥ�����������
    else if (n == 2)
        sum += a[2];
    else if (n == 1)
        sum += a[1];
    cout << sum << endl;
    return 0;
}