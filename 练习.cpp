#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Judge(int a[],int n){
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i])
			k++;
		else {
			if (k == 0 || k < 0)
				return 0;
			k--;
		}	
	}
	return k == 0;
}
int main() {
	int n;
	cin >> n;
	int i = 0, str[100];
	while (i < n)
		cin >> str[i++];
	cout << Judge(str, i);
	return 0;
}

