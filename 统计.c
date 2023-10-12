#include<stdio.h>

void findnum(int arr[], int len) {
	int maxnum = arr[0], times, maxcount = 0, i, j;
	for (i = 0; i < len; i++) {
		times = 0;
		for (j = 0; j < len; j++)
			if (arr[i] == arr[j])
				times++;
		if (times > maxcount) {
			maxcount = times;
			maxnum = arr[i];
		}
	}
	printf("%d\n", maxnum);
}

int main() {
	int n, arr[10000], i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
		scanf("%d", (arr+i));
	findnum(arr, n);
	return 0;
}
