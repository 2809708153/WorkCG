#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	int a, b, c;
	scanf("%d", &n);
	a = n / 4; b = n / 3; c = n * 2;
	for (int i = 0; i <= a; i++)
		for (int j = 0; j <= b; j++)
			for (int k = 0; k <= c; k = k + 2)
				if (i * 4 + j * 3 + k / 2 == n && i + j + k == n) 
					printf("%d %d %d\n", i, j, k);
		system("pause");
		return 0;
}
