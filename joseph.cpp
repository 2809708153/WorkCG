#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Joseph {
private:
	int n, m, k;
public:
	Joseph(int x, int y, int z) {
		n = x;
		m = y;
		k = z;
	}
	void simulate() {
		int lst[1000] = { 0 }, i, j = 0, t = 0; //数组元素全设置为零，j记录是否一个m循环，t记录是否剩余最后一个数
		for (i = k - 1; t < n - 1; i++) {
			if (i == n) //到末尾时，从头又开始
				i = 0;
			if (lst[i] != 1) //0/1记录该位置是否被踢出
				j++; 
			if (j == m) { //报数到第m个时，踢出该位置并输出
				cout << i + 1 << " ";
				lst[i] = 1;
				j = 0;
				t++;
			}
		}
		for (i = 0; i < n; i++) //循环找出最后一个剩余的位置
			if (lst[i] != 1) 
				cout << i + 1 << endl;
	}
};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	Joseph obj(n, m, k);
	obj.simulate();
	return 0;
}