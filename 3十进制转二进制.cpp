#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int x;
	cin >> x;
	string res = "";
	while (x) {
		res += to_string(x % 2);
		x /= 2;
	}
	reverse(res.begin(), res.end());
	cout << res;
	system("pause");
	return 0;
}