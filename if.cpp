#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	char c;
	scanf("%c", &c);
	switch (c) {
	case 'A': printf("add\n"); break;
	case 'D': printf("delete\n"); break;
	case 'S': printf("sort\n"); break;
	}
	system("pause");
	return 0;
}