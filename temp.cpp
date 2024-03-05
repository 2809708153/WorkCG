#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	float C, F;
	scanf("%f", &C);
	F = C * 9.0 / 5.0 + 32;
	printf("%.1f", F);
	system("pause");
	return 0;
}