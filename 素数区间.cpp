#include <iostream>
#include <stdlib.h>
using namespace std;

int f(int n) {
	int i;
	for (i = 2; i < n / 2; i++) {
		if (n%i == 0)
			return 0;
	}
	return 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	int i,count=0;
	cout << n << "至" << m << "之间的所有素数有：" << endl;
	for (i = n; i <= m; i++) {
		if (f(i)) {
			count++;
			cout <<"  "<< i ;
			if (count % 8 == 0)
				cout << endl;
		}		
	}
	system("pause");
	return 0;
}

