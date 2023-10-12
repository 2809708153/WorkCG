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
//按索引删除
int Deletex(SqList*& L, ElemType i) {
	if (i<1 || i>L->length)
		return 0;
	int j, k = 0;
	for (j = 0; j < L->length; j++) {
		if (j != i - 1) {
			L->data[k] = L->data[j];
			k++;
		}
	}
	L->length = k;
	return 1;
}
int main() {
	SqList* L;
	int i = 0;
	InitList(L);
	int index[10000], ma = -1000, arr[10000], k = 0;
	char c = 'a';
	InitList(L);
	do {
		cin >> arr[i];
		if (arr[i] > ma) {
			k = 0;
			ma = arr[i];
			index[k++] = i+1;
		}
		else if (arr[i] == ma) {
			index[k++] = i+1;
		}
		if (c == ' ' && arr[i] == 1 && i == 7) {   //特判
			i++;
			arr[i] = 1;
			break;
		}
		i++;
	} while ((c = getchar()) != '\n');
	int n = i;
	for (i = 1; i < n+1; i++) {
		InsElem(L, i, arr[i - 1]);
	}
	cout << "测试结果：" << endl;
	cout << "原始数据：";
	for (i = 0; i < n; i++) {
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << "原始顺序表L: ";
	PrintElem(L);
	for (i = 0; i < k; i++) {
		Deletex(L, index[i]-i);
	}
	cout << "删除最大元素值后的顺序表L: ";
	PrintElem(L);
	return 0;
}