#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int prime(int n) {
	int i;
	for (i = 2; i < n / 2; i++) {
		if (n % i == 0) 
			return 0;
	}
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", prime(n));
	return 0;
}