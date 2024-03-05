#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int num;
	scanf("%d", &num);
	if (num >= 100 && num <= 999) {
		int y = 0;
		for (; num > 0; num /= 10)
			y = y * 10 + num % 10;
		printf("%d", y);
	}
	else printf("-1");
	system("pause");
	return 0;
}