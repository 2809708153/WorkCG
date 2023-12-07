#include <iostream>
//#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
#define MaxSize 100
#define M 4
#define N 4
typedef int ElemType;
//定义三元组
typedef struct {
	int r;
	int c;
	ElemType d;
}TupNode;
typedef struct {
	int rows;
	int cols;
	int nums;
	TupNode data[MaxSize];
}TSMatrix;
//创建三元组
void CreatMatrix(TSMatrix& t, ElemType A[M][N]) {
	int i, j;
	t.rows = M;
	t.cols = N;
	t.nums = 0;
	for (i = 0; i < M; i++) {
		for (j = 0; j < N; j++) {
			if (A[i][j] != 0) {
				t.data[t.nums].r = i;
				t.data[t.nums].c = j;
				t.data[t.nums].d = A[i][j];
				t.nums++;
			}
		}
	}
}
//输出三元组
void DispMat(TSMatrix t) {
	int i;
	if (t.nums <= 0)
		return;
	cout << "   " << t.rows << "   " << t.cols << "   " << t.nums << endl;
	cout << "------------" << endl;
	for (i = 0; i < t.nums; i++) {
		printf("%4d", t.data[i].r);
		printf("%4d", t.data[i].c);
		printf("%4d", t.data[i].d);
		printf("\n");
	}
}
/*
//法一，先进行矩阵相加再转为三元组
void AddMatrix1(int(*p)[4], int(*q)[4], int(*t)[4], int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			t[i][j] = p[i][j] + q[i][j];
}
int main() {
	TSMatrix t1, t2, t3;
	int a1[4][4], a2[4][4], a3[4][4];
	int i, j;
	cout << "input matrix a:" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> a1[i][j];
	cout << "input matrix b:" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> a2[i][j];
	CreatMatrix(t1, a1);
	CreatMatrix(t2, a2);
	AddMatrix1(a1, a2, a3, 4);
	CreatMatrix(t3, a3);
	cout << "The triple a:" << endl;
	DispMat(t1);
	cout << "The triple b:" << endl;
	DispMat(t2);
	cout << "c=a+b" << endl;
	cout << "The triple c:" << endl;
	DispMat(t3);
	system("pause");
	return 0;
}
*/
//法二，先进行转化三元组再相加
void AddMatrix2(TSMatrix a,TSMatrix b,TSMatrix &c) {
	c.rows = a.rows;
	c.cols = a.cols;
	c.nums = 0;
	int i = 0, j = 0;
	while (i < a.nums && j < b.nums) {
		if (a.data[i].r == b.data[j].r && a.data[i].c == b.data[j].c) {
			if (a.data[i].d + b.data[j].d == 0) {
				i++;
				j++;
			}
			else {
				c.data[c.nums].r = a.data[i].r;
				c.data[c.nums].c = a.data[i].c;
				c.data[c.nums].d = a.data[i].d + b.data[j].d;
				i++;
				j++;
				c.nums++;
			}
		}
		else if ((a.data[i].r == b.data[j].r && a.data[i].c < b.data[j].c) || a.data[i].r < b.data[j].r) {
			c.data[c.nums].r = a.data[i].r;
			c.data[c.nums].c = a.data[i].c;
			c.data[c.nums].d = a.data[i].d;
			i++;
			c.nums++;
		}
		else if ((a.data[i].r == b.data[j].r && a.data[i].c > b.data[j].c) || a.data[i].r > b.data[j].r) {
			c.data[c.nums].r = b.data[j].r;
			c.data[c.nums].c = b.data[j].c;
			c.data[c.nums].d = b.data[j].d;
			j++;
			c.nums++;
		}
	}
	while (i < a.nums) {
		c.data[c.nums].r = a.data[i].r;
		c.data[c.nums].c = a.data[i].c;
		c.data[c.nums].d = a.data[i].d;
		i++;
		c.nums++;
	}
	while (j < b.nums) {
		c.data[c.nums].r = b.data[j].r;
		c.data[c.nums].c = b.data[j].c;
		c.data[c.nums].d = b.data[j].d;
		j++;
		c.nums++;
	}
}
int main() {
	TSMatrix t1, t2, t3;
	int a1[4][4], a2[4][4];
	int i, j;
	cout << "input matrix a:" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> a1[i][j];
	cout << "input matrix b:" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> a2[i][j];
	CreatMatrix(t1, a1);
	CreatMatrix(t2, a2);
	AddMatrix2(t1, t2, t3);
	cout << "The triple a:" << endl;
	DispMat(t1);
	cout << "The triple b:" << endl;
	DispMat(t2);
	cout << "c=a+b" << endl;
	cout << "The triple c:" << endl;
	DispMat(t3);
	system("pause");
	return 0;
}
