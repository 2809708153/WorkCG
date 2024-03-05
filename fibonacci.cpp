#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int f(int n) {
    if (n < 3) return 1;
    else return f(n - 1) + f(n - 2);
}
int main() {
	int num;
	scanf("%d", &num);
	int result = f(num);
	printf("%d", result);
	system("pause");
	return 0;
}


