#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n < 0) printf("error");
	else
	{
		int y = 0;
		for (; n > 0; n /= 10)
			y = y * 10 + n % 10;
		printf("%d", y);
	}
	system("pause");
	return 0;
}