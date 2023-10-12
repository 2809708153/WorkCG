#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//�ж�����  
int isPrime(int i) {
    for (int j = 2; j <= sqrt(i); ++j) 
        if (i % j == 0) 
            return 0;
    return 1;
}
int fac(int n) {
    int sum = 1;
    while (n > 0) {
        sum *= n;
        n--;
    }
    return sum;
}
int main() {
    int n, i, arr[100], k, j;
    cin >> n;
    k = fac(n);
    for (i = 0; i < n; i++)
        arr[i] = i + 1;
    for (i = 0; i < k; i++) {
        int flag = 1;
        for (j = 0; j < n; j++) {
            if (!isPrime(arr[j] + arr[(j + 1) % n])) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            for (j = 0; j < n; j++)
                cout << arr[j] << " ";
            cout << endl;
        }
        next_permutation(arr, arr + n);   //��һ��ȫ����
        if (arr[0] != 1)   //��������1û�з�����ǰ��ʱ����
            break;
    }
    return 0;
}