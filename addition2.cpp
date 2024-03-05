#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int num[20], a, b;
	scanf("%d", &a);
	int i, j;
	for (i = 1; i <= a; i++)
		scanf("%d", &num[i]);
	scanf("%d", &b);
	for (i = a + 1; i <= a + b; i++)
		scanf("%d", &num[i]);
	for (i = 1; i <= a + b; i++)
		for (j = i + 1; j < a + b + 1; j++) {
			if (num[i] > num[j]) {
				int t = num[j];
				num[j] = num[i];
				num[i] = t;
			}
		}
	for (i = 1; i <= a + b; i++)
		printf("%d#", num[i]);
	return 0;
}