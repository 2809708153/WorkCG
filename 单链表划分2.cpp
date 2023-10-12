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
void Movel(SLinkNode*& L, int index) {
	SLinkNode* p = L->next->next;
	SLinkNode* pre = L->next;
	while (p != NULL) {
		if (p->data < index) {
			pre->next = p->next;
			p->next = L->next;
			L->next = p;
			if (pre != NULL)
				p = pre->next;
			else
				p = NULL;
		}
		else {
			pre = pre->next;
			p = p->next;
		}
	}
}
int main() {
	SLinkNode* L;
	int i = 0, arr[100], n;
	cin >> n;
	while (i < n)
		cin >> arr[i++];
	int index = arr[0];
	int len = i;
	CreateListR(L, arr, len);        //β�巨����L
	DispList(L);
	Movel(L, index);
	DispList(L);
	return 0;
}