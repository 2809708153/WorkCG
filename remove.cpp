#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>

int main() {
	char str[1000], * p = str, c;
	int i = 0;
	//scanf("%s", str); ���ø�����ֹ�ո�ض�
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
			continue; //���ں�����ǰ�ƶ�һλ����ָ��p���Լ�
		}
		p++;
	}
	printf("%s", str);
	return 0;
}
/*����
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