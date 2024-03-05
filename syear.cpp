#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main() {
	int year,flag=1;
	scanf("%d", &year);
	if (year % 4 != 0) {
		flag = 0;
	}
	if (year % 100 == 0) {
		if (year % 400 != 0) {
			flag = 0;
		}
	}
	if (flag) printf("Yes\n");
	else printf("No\n");
	system("pause");
	return 0;
}