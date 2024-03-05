#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<math.h>

int InvertSequence(int x) {
	int y = 0;
	while (x > 0) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	return y;
}
int prime(int n) {
	for (int i = 2; i < sqrt(n); i++) {
		if (n % i == 0) 
			return 0;
	}
	return 1;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	for (int j = a; j <= b; j++) {
		int y = InvertSequence(j);
		if (prime(j) && prime(y)) printf("%d\n", j);
	}
	return 0;
}