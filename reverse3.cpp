#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
int InvertSequence(int x) {
	int y = 0;
	for (; x > 0; x /= 10)
		y = y * 10 + x % 10;
	return y;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", InvertSequence(n));
	return 0;
}