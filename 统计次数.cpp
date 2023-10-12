#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
	int c[10] = {0};
	int i, j, x, k;
	for (i = 0; i < 10; i++) {
		cout << "        ";
		for (j = 0; j < 10; j++) {
			cin >> x;
			for (k= 0; k < 10; k++)
				if (k == x)
					c[k]++;
		}
	}
	for (i = 0; i < 10; i++)
		cout << i << " 出现的次数：" << c[i] << endl;
	system("pause");
	return 0;
}

