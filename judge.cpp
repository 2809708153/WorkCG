#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int height, weight;
	int standard;
	scanf("%d%d", &height, &weight);
	standard = height - 110;
	if (weight >= standard + 5) printf("fat");
	else if (weight <= standard - 5) printf("thin");
	else printf("good");
	system("pause");
	return 0;
}