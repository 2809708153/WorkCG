#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


/*简单模式匹配算法*/
void Index(char S[], char T[], int* arr, int& len)//在主串S的起始位置pos处开始查找模式串T，存在返回相应位置，不存在返回0 
{
	int k = 0;
	int i, j = 0;
	for (i = 0; i < (int)strlen(S); i++) {
		while (S[i] == T[j] && S[i] != '\0') {
			j++;
			i++;
		}
		if (j == (int)strlen(T)) {
			arr[k++] = i - j + 1;
			i += j - 1;
		}
		i -= j;
		j = 0;
	}
	len = k;
	if (len == -1)
		len = 0;
}



int main() {
	char a[100], b[100];
	scanf("%s", a);
	scanf("%s", b);
	int arr[100];
	cout << "s:" << a << endl;
	cout << "t:" << b << endl;
	int len = 0;
	Index(a, b, arr, len);
	cout << "Count:" << len;
	system("pause");
	return 0;
}
