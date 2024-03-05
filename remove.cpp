#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	char str[1000], * p = str, c;
	int i = 0;
	//scanf("%s", str); 不用该语句防止空格截断
	while ((c = getchar()) != '\n') {
		*(str + i) = c;
		i++;
	}
	*(str + i) = '\0';
	while (*p != '\0') {
		if (*p >= 'A' && *p <= 'Z') {
			char* q = p;
			while (*q != '\0') {
				*q = *(q + 1);
				q++;
			}
			continue; //由于后面向前移动一位，则指针p不自加
		}
		p++;
	}
	printf("%s", str);
	return 0;
}
/*法二
#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

int main() {
	char str[1000], * p, c;
	int i = 0;
	while ((c = getchar()) != '\n') {
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	p = str;
	while (*p!='\0'){
		if (*p >= 'A' && *p <= 'Z') {
			char* q = p;
			while (*q != '\0') {
				*q = *(q + 1);
				q++;
			}
			continue;
		}
		p++;
	}
	printf("%s", str);
	system("pause");
	return 0;
}
*/