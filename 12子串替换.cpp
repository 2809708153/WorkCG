#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;

/*��ģʽƥ���㷨*/
void Index(char *S, char *T, int* arr,int &len){//������S����ʼλ��pos����ʼ����ģʽ��T�����ڷ�����Ӧλ�ã������ڷ���0 
	int k = 0;
	int i, j = 0;
	for (i = 0; i < (int)strlen(S); i++) {
		while (S[i] == T[j] && S[i] != '\0') {
			j++;
			i++;
		}
		if (j == (int)strlen(T)) {
			arr[k++] = i - j;
			i += j - 1;
		}
		i -= j;
		j = 0;
	}
	len = k;
}


int main() {
	char s[1000], ss[1000];
    char s1[100], s2[100];
	int arr[100], i, j, len, k;
	int cha = 0;
    cin >> s >> s1 >> s2;
	Index(s, s1, arr, len);
	int flag = (int)strlen(s2) - (int)strlen(s1);
	strcpy(ss, s);
	for (i = 0; i < len; i++) {
		arr[i] += cha;
		int t = (int)strlen(s);
		int count;
		for (count = 0; count < flag; count++) {
			for (j = t; j > arr[i]; j--)
				s[j] = s[j - 1];
			t++;
		}
		s[t] = '\0';
		for (k = arr[i]; k < (int)strlen(s2) + arr[i]; k++)
			s[k] = s2[k - arr[i]];
		cha += flag;
	}
	cout << "old string:" << ss << endl;
	cout << "t:" << s1 << endl;
	cout << "s:" << s2 << endl;
	cout << "new string:" << s << endl;
    return 0;
}