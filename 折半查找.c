#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int BinSearch(int* arr, int k, int n) {
	int i = 0, j = n - 1;
	int mid, res = -1;
	while (i <= j) {
		mid = (i + j) / 2;
		if (arr[mid] == k)
			res = mid - 1;
		if (arr[mid] < k)
			i = mid + 1;
		else
			j = mid - 1;
	}
	return res;
}

int main() {
	int arr[1000], i = 0;
	char ch;
	while (1) {
		scanf("%d", arr + i);
		i++;
		ch = getchar();
		if (ch == '\n')
			break;
	}
	int k;
	scanf("%d", &k);
	printf("%d", BinSearch(arr, k, i));
	return 0;
}