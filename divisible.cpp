#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int num;
	scanf("%d", &num);
	if (num % 3 == 0 && num % 5 == 0 && num % 7 == 0) printf("Can be divisible by 3,5,7.");
	else if (num % 3 != 0 && num % 5 == 0 && num % 7 == 0) printf("Can be divisible by 5,7.");
	else if (num % 3 == 0 && num % 5 != 0 && num % 7 == 0) printf("Can be divisible by 3,7.");
	else if (num % 3 == 0 && num % 5 == 0 && num % 7 != 0) printf("Can be divisible by 3,5.");
	else if (num % 3 != 0 && num % 5 != 0 && num % 7 == 0) printf("Can be divisible by 7.");
	else if (num % 3 != 0 && num % 5 == 0 && num % 7 != 0) printf("Can be divisible by 5.");
	else if (num % 3 == 0 && num % 5 != 0 && num % 7 != 0) printf("Can be divisible by 3.");
	else printf("Can not be divisible by 3,5,7.");
	system("pause");
	return 0;
}