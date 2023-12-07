#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//递归法
int Match(char* a, char* b) {
	if (*a == '\0' && *b == '\0')     //递归结束
		return 1;
	if (*a == '\0' || *b == '\0')     //递归结束
		return 0;
	if (*a == *b)
		return Match(a + 1, b + 1);   //相同继续匹配下一个
	if (*a == '?')
		return Match(a + 1, b + 1);   //？符继续匹配下一个
	if (*a == '*')
		return Match(a, b + 1) | Match(a + 1, b + 1) | Match(a + 1, b);  //*符时对应三种情况
	return 0;
}
int main() {
	char s1[100], s2[100];
	int n, i;
	FILE* input = fopen("match.in", "r");
	FILE* output = fopen("match.out", "w");
	fgets(s1, 100, input);
	s1[(int)strlen(s1) - 1] = '\0';   //将gets读取的换行换成'\0'
	fscanf(input, "%d", &n);
	fgetc(input);    //吸收换行符
	for (i = 0; i < n; i++) {
		fgets(s2, 100, input);
		if (s2[(int)strlen(s2) - 1] == '\n')   //将gets读取的换行换成'\0'，除最后一个
			s2[(int)strlen(s2) - 1] = '\0';  
		if (Match(s1, s2))
			fprintf(output, "%s\n", s2);
	}
	fclose(input);
	fclose(output);
	return 0;
}