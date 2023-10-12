#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int main() {
	int v, n, i, j, arr[1000];
	long dp[100000] = { 0 };
	scanf("%d%d", &v, &n);
	for (i = 0; i < v; i++)
		scanf("%d", (arr + i));
	dp[0] = 1;
	for (i = 0; i < v; i++)
		for (j = 1; j <= n; j++)
			if (j-arr[i]>=0)
				dp[j] += dp[j - arr[i]];
	printf("%ld", dp[n]);
	return 0;
}