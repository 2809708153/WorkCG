#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int main() {
	int a, n, sum = 0, i;
	scanf("%d%d", &a, &n);
	int p = 0;
	for (i = 0; i < n; i++) {
		p = p * 10 + a;
		sum += p;
	}
	printf("%d", sum);
	return 0;
}