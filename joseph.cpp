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
		int lst[1000] = { 0 }, i, j = 0, t = 0; //����Ԫ��ȫ����Ϊ�㣬j��¼�Ƿ�һ��mѭ����t��¼�Ƿ�ʣ�����һ����
		for (i = k - 1; t < n - 1; i++) {
			if (i == n) //��ĩβʱ����ͷ�ֿ�ʼ
				i = 0;
			if (lst[i] != 1) //0/1��¼��λ���Ƿ��߳�
				j++; 
			if (j == m) { //��������m��ʱ���߳���λ�ò����
				cout << i + 1 << " ";
				lst[i] = 1;
				j = 0;
				t++;
			}
		}
		for (i = 0; i < n; i++) //ѭ���ҳ����һ��ʣ���λ��
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