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
//���ֺ���
void Movel(SLinkNode*& L) {
	SLinkNode* p = L->next, * q, * tc;
	L->next = NULL;
	tc = L;
	while (p != NULL) {
		if (p->data & 1) {
			q = p->next;
			if (L->next == NULL) {
				p->next = L->next;
				L->next = p;
				tc = p;
			}
			else {
				p->next = L->next;
				L->next = p;
			}
			p = q;
		}
		else {
			tc->next = p;
			tc = p;
			p = p->next;
		}
	}
	tc->next = NULL;
}
int main() {
	SLinkNode* L;
	int i = 0, arr[100], n;
	cin >> n;
	while (i < n)
		cin >> arr[i++];
	int len = i;
	CreateListR(L, arr, len);        //β�巨����L
	cout << "before Move:";
	DispList(L);
	Movel(L);
	cout << "after Move:";
	DispList(L);
	return 0;
}