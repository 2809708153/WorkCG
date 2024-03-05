#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	int num[1000], n;
	scanf("%d", &n);
	int i;
	for (i = 0; i < n; i++)
		scanf("%d", &num[i]);
	int index = 0, min = num[0];
	for (i = 1; i < n; i++) {
		if (num[i] < min) {
			min = num[i];
			index = i;
		}
	}
	printf("%d\n%d", min, index);
	return 0;
}