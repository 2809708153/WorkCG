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
//销毁顺序表
int DestroyList(SqList*& L) {
	free(L);
	return 1;
}
//求顺序表长度
int ListLength(SqList* L) {
	return L->length;
}
//按索引查找
int GetElem(SqList* L, int i, ElemType& e) {
	if (i<1 || i>L->length)
		return 0;
	else {
		e = L->data[i - 1];
		return 1;
	}
}
//按值查找
int LocateElem(SqList*& L, int i, ElemType& e) {
	int j;
	for (j = 0; j < L->length; j++)
		if (L->data[j] == i) {
			e = j + 1;
			return 1;
		}
	return 0;
}
//输入存储数据
void InsElem(SqList*& L, int i, int e) {
	int j;
	for (j = L->length; j > i - 1; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
}
//按索引插入
int InsertElem(SqList*& L, int i, int e) {
	if (i<1 || i>L->length)
		return 0;
	int j;
	for (j = L->length; j > i - 1; j--)
		L->data[j] = L->data[j - 1];
	L->data[i - 1] = e;
	L->length++;
	return 1;
}
//按索引删除
int Deletex(SqList*& L, ElemType i, int& e) {
	if (i<1 || i>L->length)
		return 0;
	int j, k = 0;
	e = L->data[i - 1];
	for (j = 0; j < L->length; j++) {
		if (j != i - 1) {
			L->data[k] = L->data[j];
			k++;
		}
	}
	L->length = k;
	return 1;
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
	int i = 0, arr[100];
	char c;
	InitList(L);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len = i;
	for (i = 1; i < len+1; i++)
		InsElem(L, i, arr[i-1]);
	cout << "测试结果：" << endl;
	cout << "原始数据：";
	for (i = 0; i < len; i++)
		cout << arr[i] << "  ";
	cout << endl;
	cout << "原始顺序表L: ";
	PrintElem(L);
	cout << "  长度:" << ListLength(L) << endl;
	int j, t;
	cin >> j >> t;
	if (InsertElem(L, j, t)) {
		cout << "插入后的顺序表为L: ";
		PrintElem(L);
		cout << "  长度:" << ListLength(L) << endl;
	}
	else {
		cout << "插入位置非法！" << endl;
		cout << "  长度:" << ListLength(L) << endl;
	}
	int e;
	cin >> i;
	if (GetElem(L, i, e)) {
		cout << "  第" << i << "个元素:" << e << endl;
	}
	else
		cout << "不存在第" << i << "个元素" << endl;
	cin >> i;
	if (LocateElem(L, i, e)) {
		cout << "查找：元素" << i << "是第" << e << "个元素" << endl;
	}
	else
		cout << "待查找元素"<<i<<"不存在！" << endl;
	cin >> i;
	if (Deletex(L, i, e)) {
		cout << "删除后的顺序表为L: ";
		PrintElem(L);
	}
	else
		cout << "  删除第" << i << "个元素不存在！" << endl;
	cout << "  长度:" << ListLength(L) << endl;
	DestroyList(L);
	cout << "销毁L";
	return 0;
}