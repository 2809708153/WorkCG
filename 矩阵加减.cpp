#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Matrix(int(*p)[100], int(*q)[100], int n, char c) {
    int i, j;
    if (c == '+') 
        for (i = 0; i < n; i++) 
            for (j = 0; j < n; j++) 
                p[i][j] += q[i][j];
    else if (c == '-')
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                p[i][j] -= q[i][j];
}
int main() {
    int n, i, j, arr1[100][100], arr2[100][100];
    char c;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> arr1[i][j];
    while (1) {
        c = getchar();   //ÎüÊÕ»»ÐÐ·û
        c = getchar();
        if (c == '#')
            break;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                cin >> arr2[i][j];
        Matrix(arr1, arr2, n, c);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%5d", arr1[i][j]);
        printf("\n");
    }
        
    return 0;
}