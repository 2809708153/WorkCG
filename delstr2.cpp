#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>
void del(char* s, int i, int n) {
	int len = strlen(s), j;
	for (j = i + n - 1; j <= len; j++) 
		*(s + j - n) = *(s + j);
}
int main() {
	char str[100];
	int i, n;
	scanf("%s", str);
	scanf("%d%d", &i, &n);
	del(str, i, n);
	printf("%s", str);
	return 0;
}