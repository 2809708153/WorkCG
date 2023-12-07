#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ݹ鷨
int Match(char* a, char* b) {
	if (*a == '\0' && *b == '\0')     //�ݹ����
		return 1;
	if (*a == '\0' || *b == '\0')     //�ݹ����
		return 0;
	if (*a == *b)
		return Match(a + 1, b + 1);   //��ͬ����ƥ����һ��
	if (*a == '?')
		return Match(a + 1, b + 1);   //��������ƥ����һ��
	if (*a == '*')
		return Match(a, b + 1) | Match(a + 1, b + 1) | Match(a + 1, b);  //*��ʱ��Ӧ�������
	return 0;
}
int main() {
	char s1[100], s2[100];
	int n, i;
	FILE* input = fopen("match.in", "r");
	FILE* output = fopen("match.out", "w");
	fgets(s1, 100, input);
	s1[(int)strlen(s1) - 1] = '\0';   //��gets��ȡ�Ļ��л���'\0'
	fscanf(input, "%d", &n);
	fgetc(input);    //���ջ��з�
	for (i = 0; i < n; i++) {
		fgets(s2, 100, input);
		if (s2[(int)strlen(s2) - 1] == '\n')   //��gets��ȡ�Ļ��л���'\0'�������һ��
			s2[(int)strlen(s2) - 1] = '\0';  
		if (Match(s1, s2))
			fprintf(output, "%s\n", s2);
	}
	fclose(input);
	fclose(output);
	return 0;
}