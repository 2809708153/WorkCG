#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//链表数据类型
typedef int ElemType;


//定义链表
typedef struct node {
	ElemType data;
	int freq;
	struct node* prior, * next;
}DLinkNode;

//初始化
void InitList(DLinkNode*& L) {
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
}
//按值查找
int Locate(DLinkNode*& L, ElemType e) {
	DLinkNode* p = L->next;
	int j = 1;
	while (p != NULL && p->data != e) {
		p = p->next;
		j++;
	}
	if (p == NULL)
		return 0;
	else {
		p->freq++;
		return j;
	}	
}
//特殊输出链表
void DispList(DLinkNode* L) {
	DLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << "[" << p->freq << "]" << " ";
		p = p->next;
	}
	cout << endl;
}
//尾插法，整体创建链表
void CreateListR(DLinkNode*& L, ElemType* a, int n) {
	DLinkNode* s, * tc;
	int i;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->freq = 0;
		tc->next = s;
		s->prior = tc;
		tc = s;
	}
	tc->next = NULL;
}
//链表按频度排序
void SortList(DLinkNode*& L) {
	DLinkNode* p, * pre, * q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->freq > p->freq)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
//链表频度相同按结点值排序
void SortListData(DLinkNode*& L) {
	DLinkNode* p, * pre, * q;
	p = L->next->next;
	L->next->next = NULL;
	while (p != NULL) {
		q = p->next;
		pre = L;
		while (pre->next != NULL && pre->next->freq == p->freq && pre->next->data == p->data)
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
}
int main() {
	DLinkNode* L;
	int i = 0, arr[100], index[100];
	char c;
	InitList(L);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len1 = i;
	CreateListR(L, arr, len1);        //尾插法创建L1
	i = 0;
	do {
		cin >> index[i++];
	} while ((c = getchar()) != '\n');
	int len2 = i;
	cout << "L: ";
	DispList(L);
	for (i = 0; i < len2; i++) {
		if (Locate(L, index[i])) {
			cout << "查找" << index[i] << "结点 查找后L: ";
			SortListData(L);
			SortList(L);
			DispList(L);
		}
		else
			cout << "查找" << index[i] << "结点 " << index[i] << "没有找到!" << endl;
	}
	return 0;
}