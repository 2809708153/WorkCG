#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int InvertSequence(int x) {
	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}
int loop(int x) {
	int flag;
	flag = (x == InvertSequence(x)) ? 1 : 0;
	return flag;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int i = a; i <= b; i++)
		if (loop(i)) printf("%d\n", i);
	return 0;
}