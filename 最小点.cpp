#include <iostream>
#include <stdlib.h>
using namespace std;

int judge(int arr[][10], int k, int i, int j, int n, int m) {
	int a, leap = 1;
	for (a = 0; a < n; a++)
		if (arr[a][j] < k) {
			leap = 0;
			break;
		}
	for (a = 0; a < m; a++)
		if (arr[i][a] < k) {
			leap = 0;
			break;
		}
	return leap;
}
int main() {
	int arr[10][10], n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			scanf("%d", &arr[i][j]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (judge(arr, arr[i][j], i, j, n, m))
				printf("%d %d %d\n", arr[i][j], i + 1, j + 1);
	system("pause");
	return 0;
}
