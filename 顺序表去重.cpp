#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define MaxSize 100
typedef int ElemType;

typedef struct {
	ElemType data[MaxSize];
	int length;
} SqList;
//初始化顺序表
int InitList(SqList*& L) {
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
	return 1;
}
//输入存储数据
void InsElem(SqList*& L, int i, int e) {
	int j;
	for (j = L->length; j > i - 1; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
}
//输出顺序表
void PrintElem(SqList* L) {
	int i;
	for (i = 0; i < L->length; i++)
		cout << L->data[i] << " ";
	cout << endl;
}

int main() {
	SqList* L;
	int i = 0, arr[100], n, j;
	cin >> n;
	InitList(L);
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = 1; i < n + 1; i++)
		InsElem(L, i, arr[i - 1]);
	i = 0;
	n = L->length;
	while (i < n - 1) {
		if (L->data[i] == L->data[i + 1]) {
			for (j = i; j < n; j++)
				L->data[j] = L->data[j + 1];
			n--;
		}
		else
			i++;
	}
	L->length = n;
	PrintElem(L);
	return 0;
}