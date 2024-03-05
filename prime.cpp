#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

void f(int n) {
	int flag = 1;
	for (int i = 2; i < n / 2; i++) {
		if (n % i == 0) {
			flag = 0;
		}
	}
	if (flag == 1) printf("%d\n", n);
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int j = a; j <= b; j++) {
		f(j);
	}
	system("pause");
	return 0;
}