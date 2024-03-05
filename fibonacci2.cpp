#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>

int f(int x) {
	if (x < 2 && x >= 0) 
		return 1;
	else 
		return f(x - 1) + f(x - 2);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("%d", f(n));
	return 0;
}