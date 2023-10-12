#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <bits/stdc++.h>

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
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
//��·�鲢
void Merge(SLinkNode* ha, SLinkNode* hb, SLinkNode*& hc) {
	SLinkNode* pa = ha->next, * pb = hb->next, * tc;
	hc = ha;
	tc = hc;
	while (pa != NULL && pb != NULL) {
		if (pa->data < pb->data) {
			tc->next = pa;
			tc = pa;
			pa = pa->next;
		}
		else if (pa->data > pb->data){
			tc->next = pb;
			tc = pb;
			pb = pb->next;
		}
		else {
			tc->next = pa;
			tc = pa;
			pa = pa->next;
			pb = pb->next;
		}
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
//����ȥ��
void Del(SLinkNode*& L) {
	SLinkNode* p = L->next, * pre = L;
	while (p != NULL) {
		if (p->data==pre->data) {
			pre->next = p->next;
			free(p);
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}
}
int main() {
	SLinkNode* L1, * L2, * L3;
	int i = 0, arr[100];
	int n1, n2;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	scanf("%d%d", &n1, &n2);
	do {
		scanf("%d", &arr[i++]);
	} while (i<n1);
	int len = i;
	CreateListR(L1, arr, len);        //β�巨����L1
	i = 0;
	do {
		scanf("%d", &arr[i++]);
	} while (i<n2);
	len = i;
	CreateListR(L2, arr, len);        //β�巨����L2
	Merge(L1, L2, L3);                //�鲢
	Del(L3);
	DispList(L3);
	return 0;
}