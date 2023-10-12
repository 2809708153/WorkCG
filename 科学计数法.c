#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	char str[100];
	scanf("%s", str);
	double a, b;
	sscanf(str, "%lfe%lf", &a, &b);
	double res = a * pow(10, b);
	printf("%.6lf", res);
	return 0;
}