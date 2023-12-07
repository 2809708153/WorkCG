#include <iostream>
#include <bits/stdc++.h>
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
//矩阵相乘
void MulMatrix(int(*p)[4],int (*q)[4],int (*t)[4]) {
    int i, j, k;
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            int sum = 0;
            for (k = 0; k < N; k++) 
                sum += p[i][k] * q[k][j];
            t[i][j] = sum;
        }
        
    }
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
    MulMatrix(a1, a2, a3);
    CreatMatrix(t1, a1);
    CreatMatrix(t2, a2);
    CreatMatrix(t3, a3);
    cout << "The triple a:" << endl;
    DispMat(t1);
    cout << "The triple b:" << endl;
    DispMat(t2);
    cout << "c=a*b" << endl;
    cout << "The triple c:" << endl;
    DispMat(t3);
    return 0;
}