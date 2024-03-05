#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, c, sum;
	float aver;
	scanf("%d%d%d", &a, &b, &c);
	sum = a + b + c;
	aver = sum / 3.0;
	printf("%d\n%.2f", sum, aver);
	system("pause");
	return 0;
}