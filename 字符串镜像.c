#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>

int Comp(char* a, char* b ,int l1, int l2) {
	int i = 0, j = l2 - 1;
	while (a[i] == b[j] && i<l1) {
		i++;
		j--;
	}
	return j == -1;
}
int main() {
	char str1[1000], str2[1000];
	char c;
	int flag = 1, i = 0, j = 0;
	while ((c = getchar()) != '@') {
		if (c == '&') {
			flag = 0;
			continue;
		}
		if (flag)
			str1[i++] = c;
		else
			str2[j++] = c;
	}
	str1[i] = '\0';
	str2[j] = '\0';
	if (Comp(str1, str2, i, j))
		printf("%d", i);
	else
		printf("no");
	return 0;
}