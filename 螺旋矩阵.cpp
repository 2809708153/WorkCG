#include<iostream>
using namespace std;

//len��ʾ����ı߳���Ҳ����һ��������� , k��ʾ��ǰ�ǵڼ������� 
void f(int s, int len, int k, int(*a)[100], int n) {
	if (len == 1){
		a[k][k] = s;
		return;   //�ݹ����
	}
	else if (len == 2){
		a[k][k] = s++;
		a[k][k + 1] = s++;
		a[k + 1][k + 1] = s++;
		a[k + 1][k] = s;
		return;
	}
	//�����ϱ߿� 
	int col = n + 1 - k;			//��ʾ�ұ߿���кź��±߿���к� 
	int x = s;
	for (int j = k; j <= col; j++) {
		a[k][j] = x;
		x++;
	}
	//�����ұ߿�
	for (int i = k + 1; i <= col; i++){
		a[i][col] = x;
		x++;
	}
	//�����±߿�
	for (int j = col - 1; j >= k; j--){
		a[col][j] = x;
		x++;
	}
	//������߿�
	for (int i = col - 1; i >= k + 1; i--){
		a[i][k] = x;
		x++;
	}
	f(x, len - 2, k + 1, a, n);		//�ݹ����С��������
}

int main(){
	int n;
	int a[100][100];
	cin >> n;
	f(1, n, 1, a, n);			   //��k = 1��ʼ����һ������ 
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			printf("%5d", a[i][j]);
		}
		cout << endl;
	}
	return 0;
}