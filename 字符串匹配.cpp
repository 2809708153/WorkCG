#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//��һ ��ģʽƥ���㷨
int Index(char* S, char* T, int pos) {//������S����ʼλ��pos����ʼ����ģʽ��T�����ڷ�����Ӧλ�ã������ڷ���0  
	int i, j = 0;
	for (i = pos; i < strlen(S); i++) {
		while (S[i] == T[j] && S[i] != '\0') {
			j++;
			i++;
		}
		if (j == strlen(T) && i == strlen(S))
			return i;
		i -= j;
		j = 0;
	}
	return 0;
}
int main() {
	char a[100], b[100];
	int n = 0;
	scanf("%s%s", a, b);
	int index = Index(a, b, n);
	if (index)
		printf("Yes");
	else
		printf("No");
	system("pause");
	return 0;
}


