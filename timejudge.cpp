#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	c++;
	if (c == 60) { b++; c = 0; }
	if (b == 60) { a++; b = 0; }
	if (a == 24) {
		a = 0;
		b = 0;
		c = 0;
	}
	printf("%d:%d:%d", a, b, c);
	system("pause");
	return 0;
}