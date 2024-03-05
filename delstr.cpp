#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>
void del(char* s, int i, int n) {
	char* p = s, * q = s;
	p = p + i - 1;
	q = q + i + n - 1;
	strcpy(p, q);
}
int main() {
	char str[51];
	int i, n;
	scanf("%s", str);
	scanf("%d%d", &i, &n);
	del(str, i, n);
	printf("%s", str);
	return 0;
}