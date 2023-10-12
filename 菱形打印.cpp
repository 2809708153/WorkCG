#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

void print(int i, int s) {
	int k, j;
	k = 2 * i - 1;
	int q = (s - k) / 2;
	for (j = 0; j < q; j++)
		cout << " ";
	for (j = 0; j < k; j++)
		cout << "*";
	cout << endl;
}

int main() {
	int n, i = 1, count = 1;
	cin >> n;
	int s = 2 * n - 1;
	while (i > 0) {
		print(i, s);
		count++;
		if (count >= n)
			i--;
		else
			i++;
	}
	system("pause");
	return 0;
}