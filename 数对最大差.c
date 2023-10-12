#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int main() {
	int arr[100], i = 0, j, res = -1000;
	char c;
	do {
		scanf("%d", &arr[i++]);
	} while ((c = getchar()) != '\n');
	int len = i;
	for (i = 0; i < len - 1; i++)
		for (j = i + 1; j < len; j++)
			if (arr[i] - arr[j] > res)
				res = arr[i] - arr[j];
	printf("%d\n", res);
	return 0;
}