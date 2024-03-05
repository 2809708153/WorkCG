#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
int strcompare(char* str1, char* str2) {
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0') {
		str1++;
		str2++;
	}
	return int(*str1 - *str2);
}
int main() {
	char s1[1000], s2[1000];
	scanf("%s", s1);
	scanf("%s", s2);
	printf("%d", strcompare(s1, s2));
	return 0;
}