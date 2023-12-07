#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int SubMatrix(int(*p)[100], int(*q)[100], int n1, int n2, int* a, int* b) {
	int count = 0, i, j, m, n;
	for (i = 0; i < n1; i++) {
		for (j = 0; j < n1; j++) {
			if (p[i][j] == q[0][0]) {
				count = 0;
				for (m = 0; m < n2; m++) {
					for (n = 0; n < n2; n++) {
						if (p[i + m][j + n] == q[m][n])
							count++;
						else
							break;
					}
					if (p[i + m][j + n] != q[m][n])
						break;
				}
			}
			if (count == n2 * n2) {
				*a = i + 1;
				*b = j + 1;
				return 1;
			}
		}
		if (count == n2 * n2) {
			*a = i + 1;
			*b = j + 1;
			return 1;
		}
	}
	return 0;
}
int main() {
	int arr1[100][100], arr2[100][100];
	int n1, n2, i, j, a, b;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++) 
		for (j = 0; j < n1; j++) 
			scanf("%d", &arr1[i][j]);
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
		for (j = 0; j < n2; j++)
			scanf("%d", &arr2[i][j]);
	if (SubMatrix(arr1, arr2, n1, n2, &a, &b))
		printf("%d,%d", a, b);
	else
		printf("-1");
	return 0;
}