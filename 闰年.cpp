#include <iostream>
#include <stdlib.h>
using namespace std;
bool is_leap_year(int year){
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else
		return 0;
}

int main() {
	int n, m, i;
	cin >> n >> m;
	int count = 0;
	cout << n << "年至" << m << "年间的闰年有:" << endl;
	for (i = n; i < m; i++) {
		if (is_leap_year(i)) {
			count++;
			cout << "  " << i;
			if (count % 5 == 0)
				cout << endl;
		}
	}
	system("pause");
	return 0;
}

