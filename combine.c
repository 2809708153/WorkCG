#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int comb(int a, int b) {
	return a % 10 * 1000 + b % 10 * 100 + a / 10 * 10 + b / 10;
}
int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", comb(x, y));
	return 0;
}