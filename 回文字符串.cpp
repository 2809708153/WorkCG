#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

int Hwen(char* str) {
	int i = 0, j = strlen(str) - 1;
	while (i < j) {
		if (str[i] != str[j])
			return 0;
		i++;
		j--;
	}
	return 1;
}
int main() {
	char s[100];
	scanf("%s", s);
	if (Hwen(s))
		printf("yes");
	else
		printf("no");
	return 0;
}