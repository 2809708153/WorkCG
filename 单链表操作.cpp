#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define MaxSize 100
typedef int ElemType;

//定义链表
typedef struct node {
	ElemType data;
	struct node* next;
}SLinkNode;
//初始化顺序表
void InitList(SLinkNode*& L) {
	L = (SLinkNode*)malloc(sizeof(SLinkNode));
	L->next = NULL;
}
//销毁
void DestroyList(SLinkNode*& L) {
	SLinkNode* pre = L, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}
//求长度
int GetLength(SLinkNode* L) {
	int i = 0;
	SLinkNode* p = L->next;
	while (p != NULL) {
		i++;
		p = p->next;
	}
	return i;
}
//求第i个元素
int GetElem(SLinkNode* L, int i, ElemType& e) {
	int j = 0;
	SLinkNode* p = L;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		e = p->data;
		return 1;
	}
}
//按值查找
int Locate(SLinkNode* L, ElemType e) {
	SLinkNode* p = L->next;
	int j = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else
		return j;
}
//插入元素
int InsElem(SLinkNode*& L,int i ,ElemType x ) {
	int j = 0;
	SLinkNode* p = L, * s;
	if (i <= 0)
		return 0;
	while (p != NULL && j < i - 1) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else {
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = x;
		s->next = p->next;
		p->next = s;
		return 1;
	}
}
//删除元素
int DelElem(SLinkNode*& L, int i) {
	int j = 0;
	SLinkNode* p = L, * q;
	while (p != NULL && j < i - 1) {
		j++;
		p = p->next;
	}
	if (p == NULL)
		return 0;
	else {
		q = p->next;
		if (q == NULL)
			return 0;
		else {
			p->next = q->next;
			free(q);
			return 1;
		}
	}
}
//输出链表
void DispList(SLinkNode* L) {
	SLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//头插法，整体创建链表
void CreateListF(SLinkNode*& L, ElemType* a, int n) {
	SLinkNode* s;
	int i;
	L = (SLinkNode*)malloc(sizeof(SLinkNode));
	L->next = NULL;
	for (i = 0; i < n; i++) {
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
int main() {
	SLinkNode* L;
	int i = 0, arr[100];
	char c;
	InitList(L);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len = i;
	CreateListF(L, arr, len);
	cout << "测试结果：" << endl;
	cout << "原始数据：";
	for (i = 0; i < len; i++)
		cout << arr[i] << "  ";
	cout << endl;
	cout << "原始单链表L: ";
	DispList(L);
	cout << "  长度:" << GetLength(L) << endl;
	int j, t;
	cin >> j >> t;
	if (InsElem(L, j, t)) {
		cout << "插入后的单链表为L: ";
		DispList(L);
		cout << "  长度:" << GetLength(L) << endl;
	}
	else {
		cout << "插入位置非法！" << endl;
		cout << "  长度:" << GetLength(L) << endl;
	}
	int e;
	cin >> i;
	if (GetElem(L, i, e)) {
		cout << "  第" << i << "个元素:" << e << endl;
	}
	else
		cout << "不存在第" << i << "个元素" << endl;
	cin >> i;
	if (Locate(L, i)) {
		cout << "查找：元素" << i << "是第" << Locate(L, i) << "个元素" << endl;
	}
	else
		cout << "待查找元素" << i << "不存在！" << endl;
	cin >> i;
	if (DelElem(L, i)) {
		cout << "删除后的单链表为L: ";
		DispList(L);
	}
	else
		cout << "  删除第" << i << "个元素不存在！" << endl;
	cout << "  长度:" << GetLength(L) << endl;
	DestroyList(L);
	cout << "销毁L";
	return 0;
}