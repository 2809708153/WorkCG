#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#define f(n) n*n*3.14

int main() {
	float n;
	scanf("%f", &n);
	printf("s=%.2f", f(n));
	system("pause");
	return 0;
}