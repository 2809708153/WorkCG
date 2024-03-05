#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int a[10], b[10], c[20];
	int m, n, i, j, k = 0;
	scanf("%d", &m);
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d", &b[i]);
	for (i = 0, j = 0; i < m && j < n; k++) {
		if (a[i] < b[j]) c[k] = a[i++];
		else c[k] = b[j++];
	}
	while (i < m) {
		c[k] = a[i];
		k++; i++;
	}
	while (j < n) {
		c[k] = b[j];
		k++; j++;
	}
	for (i = 0; i < k; i++) printf("%d#", c[i]);
	return 0;
}