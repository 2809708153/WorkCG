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
//�������
void DispList(SLinkNode* L) {
	SLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//��·�鲢
void Merge(SLinkNode* ha, SLinkNode* hb, SLinkNode*& hc) {
	SLinkNode* pa = ha->next, * pb = hb->next, * tc;
	hc = ha;
	tc = hc;
	int i = 1;
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			tc->next = pa;
			tc = pa;
			pa = pa->next;
		}
		else {
			tc->next = pb;
			tc = pb;
			pb = pb->next;
		}
		i++;
	}
	tc->next = NULL;
	if (pa != NULL)
		tc->next = pa;
	if (pb != NULL)
		tc->next = pb;
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


int main() {
	SLinkNode* L1, * L2, * L3;
	int i = 0, arr[100];
	InitList(L1);
	InitList(L2);
	InitList(L3);
	int a, b;
	cin >> a >> b;
	while (a--)
		cin >> arr[i++];
	int len = i;
	CreateListR(L1, arr, len);        //β�巨����L1
	i = 0;
	while (b--)
		cin >> arr[i++];
	len = i;
	CreateListR(L2, arr, len);        //β�巨����L2
	cout << "ha:";
	DispList(L1);
	cout << "hb:";
	DispList(L2);
	Merge(L1, L2, L3);                //�鲢
	cout << "hc:";
	DispList(L3);
	return 0;
}