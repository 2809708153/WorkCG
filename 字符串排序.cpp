#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void swap(char *p, char *q) {
	char *s = (char *)malloc(100);
	strcpy(s, p);
	strcpy(p, q);
	strcpy(q, s);
	free(s);
}

int main() {
	char str1[100], str2[100], str3[100];
	cin.getline(str1, 100);
	cin.getline(str2, 100);
	cin.getline(str3, 100);
	if (strcmp(str1, str2) > 0)
		swap(str1, str2);
	if (strcmp(str2, str3) > 0)
		swap(str2, str3);
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	system("pause");
	return 0;
}

