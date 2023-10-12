#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define MaxSize 10000
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
	SqList* L, * L1;
	int i = 0, arr[10000], n, j, k = 0;
	char c;
	InitList(L);
	InitList(L1);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	n = i;
	for (i = 1; i < n + 1; i++)
		InsElem(L, i, arr[i - 1]);
	cout << "测试结果：" << endl;
	cout << "原始数据：";
	for (i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << "初始顺序表L:  ";
	PrintElem(L);
	i = 0;
	n = L->length;
	while (i < n) {
		if (!(L->data[i] & 1)) {
			int t = L->data[i];
			for (j = i; j < n-1; j++)
				L->data[j] = L->data[j + 1];
			n--;
			L1->data[k++] = t;
			L1->length++;
		}
		else
			i++;
	}
	L->length = n;
	cout << "拆分后：" << endl;
	cout << "奇数顺序表L:  ";
	PrintElem(L);
	cout << "偶数顺序表L1: ";
	PrintElem(L1);
	return 0;
}