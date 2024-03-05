#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int BinSearch(int* arr, int k, int n,int *flag,int *num,int *count) {
	int i = 0, j = n - 1;
	int mid;
	while (i <= j) {
		mid = (i + j) / 2;
		num[(*count)++] = arr[mid];
		if (arr[mid] == k) {
			return mid;
		}
		if (arr[mid] < k)
			i = mid + 1;
		else
			j = mid - 1;
	}
	*flag = 0;
	return 0;
}

int main() {
	int arr[1000], n, i, num[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", arr + i);
		getchar();
	}
	int k, flag = 1, count = 0;
	scanf("%d", &k);
	int ans = BinSearch(arr, k, n, &flag, num, &count);
	if (flag) {
		printf("%d\n", ans);
		for (i = 0; i < count; i++) {
			if (i == 0)
				printf("%d", num[i]);
			else
				printf(",%d", num[i]);
		}
	}
	else {
		printf("no\n");
		for (i = 0; i < count; i++) {
			if (i == 0)
				printf("%d", num[i]);
			else
				printf(",%d", num[i]);
		}
	}
	return 0;
}