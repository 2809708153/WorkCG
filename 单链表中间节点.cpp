#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define MaxSize 100
typedef int ElemType;

//��������
typedef struct node {
	ElemType data;
	struct node* next;
}SLinkNode;
//��ʼ��˳���
void InitList(SLinkNode*& L) {
	L = (SLinkNode*)malloc(sizeof(SLinkNode));
	L->next = NULL;
}
//β�巨�����崴������
void CreateListR(SLinkNode*& L, ElemType* a, int n) {
	SLinkNode* s, * tc;
	int i;
	L = (SLinkNode*)malloc(sizeof(SLinkNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (SLinkNode*)malloc(sizeof(SLinkNode));
		s->data = a[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}
//�������
void DispList(SLinkNode* L) {
	SLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
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

int main() {
	SLinkNode* L;
	int i = 0, arr[100], n, e = 0;
	cin >> n;
	int index;
	if (n & 1)
		index = n / 2 + 1;
	else
		index = n / 2;
	while (i < n)
		cin >> arr[i++];
	int len = i;
	CreateListR(L, arr, len);        //β�巨����L
	GetElem(L, index, e);
	cout << e << endl;
	return 0;
}