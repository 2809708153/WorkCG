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
//稀疏矩阵快速转置
void TransMatrix(TSMatrix t, TSMatrix& s) {
	s.rows = t.cols;
	s.cols = t.rows;
	s.nums = t.nums;
	int num[100] = { 0 }, cpot[100] = { 0 }, i;
	for (i = 0; i < s.nums; i++)
		num[t.data[i].c]++;
	cpot[0] = 0;
	for (i = 1; i < s.nums; i++)
		cpot[i] = cpot[i - 1] + num[i - 1];
	for (i = 0; i < s.nums; i++) {
		int k = cpot[t.data[i].c]++;
		s.data[k].r = t.data[i].c;
		s.data[k].c = t.data[i].r;
		s.data[k].d = t.data[i].d;
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

int main() {
	TSMatrix t1, t2;
	int a1[4][4];
	int i, j;
	cout << "input matrix a:" << endl;
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			cin >> a1[i][j];
	CreatMatrix(t1, a1);
	TransMatrix(t1, t2);
	cout << "The triple a:" << endl;
	DispMat(t1);
	cout << "a to b:" << endl;
	cout << "The triple b:" << endl;
	DispMat(t2);
	system("pause");
	return 0;
}