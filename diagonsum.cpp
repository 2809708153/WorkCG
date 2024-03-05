#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int lst[4][4], i, j, sum = 0, (*p)[4] = lst;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			scanf("%d", (*(p + i) + j));
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (i == j)
				sum += *(*(p + i) + j);
	printf("%d", sum);
	return 0;
}