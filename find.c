#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <string.h>

int main() {
	char str[100], ch, c;
	int index[100], k = 0;
	//gets(str);
	while ((c = getchar()) != '\n') {
		str[k++] = c;
	}
	str[k] = '\0';
	scanf("%c", &ch);
	int i, s = strlen(str), j = 0, count = 0;
	for (i = 0; i < s; i++) {
		if (str[i] == ch) {
			count++;
			index[j] = i;
			j++;
		}
	}
	if (count == 0) printf("No match!");
	else {
		printf("%d\n", count);
		for (i = 0; i < j; i++)
			printf("%d ", index[i]);
	}
	return 0;
}