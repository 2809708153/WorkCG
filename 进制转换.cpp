#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void reverse(char* str) {
	int i = 0, j = strlen(str) - 1;
	while (i < j) {
		char t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
}
int bin2dec(const char * const str) {
	int s = strlen(str);
	int i, sum = 0;
	int k = 0;
	for (i = 0; i < s; i++) {
		if (str[i] == '1')
			sum += pow(2, k);
		k++;
	}
	return sum;
}

int main() {
	char s[100];
	cin >> s;
	reverse(s);
	cout << bin2dec(s);
	system("pause");
	return 0;
}

