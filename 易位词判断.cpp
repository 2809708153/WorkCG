#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//int Yiwei(string s1, string s2, int* num) {
//	int i, j;
//	if (s1.length() != s2.length())
//		return 1;
//	for (i = 0; i < (int)s1.length(); i++)
//		num[s1[i] - 'a']++;
//	for (j = 0; j < (int)s2.length(); j++)
//		if (--num[s2[j] - 'a'] < 0)
//			return 0;
//	return 1;
//}
//ÓÅ»¯
int Yiwei(string s1, string s2, int* num) {
	int i;
	if (s1.length() != s2.length())
		return 1;
	for (i = 0; i < (int)s1.length(); i++) {
		num[s1[i] - 'a']++;
		num[s2[i] - 'a']--;
	}
	for (i = 0; i < 26; i++)
		if (num[i] != 0)
			return 0;
	return 1;
}
int main() {
    string a, b;
	int num[26] = { 0 };
	cin >> a >> b;
	if (Yiwei(a, b, num))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
    return 0;
}