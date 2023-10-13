#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int datatype;

typedef struct node {
    datatype data;
    node* link;
}LinkNode;

//��ʼ������
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->link = NULL;
}
//����
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = pre->link;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->link;
	}
	free(pre);
}
//�������
void DispList(LinkNode* L) {
	LinkNode* p = L->link;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}
//��һ   ����˼·�����ȱ��������ҵ������Ǹ���Ȼ��ɾ����¼�����ӵ�ĩβ��
/*//ɾ�������
void Delmax(LinkNode*& L, int a) {
	LinkNode* p = L->link, * pre = L;
	while (p != NULL) {
		if (p->data == a) {
			pre->link = p->link;
			free(p);
			p = pre->link;
		}
		else {
			pre = p;
			p = p->link;
		}
	}
}
void MovemaxNode(LinkNode*& L) {
	LinkNode* p = L->link->link;
	int ma = L->link->data;
	while (p) {
		if (p->data > ma)
			ma = p->data;
		p = p->link;
	}
	Delmax(L, ma);
	p = L->link;
	while (p->link) {
		p = p->link;
	}
	LinkNode* s;
	s = (LinkNode*)malloc(sizeof(LinkNode));
	p->link = s;
	s->data = ma;
	s->link = NULL;
}*/
//����   ����˼·���Է�һ�Ż����ȱ��������ҵ�����㲢��¼����ǰһ��㣬Ȼ��ı�ָ��ָ��
void MovemaxNode(LinkNode*& L) {
	//�ֱ��ǵ�ǰ��㣬����㣬������ǰһ��㣬��ǰ������һ���
	LinkNode* p = L->link->link, * maxnode = L->link, * maxprenode = L, *pre = L->link;
	while (p) {
		if (p->data > maxnode->data) {
			maxnode = p;
			maxprenode = pre;
		}
		p = p->link;
		pre = pre->link;
		if (p->link == NULL) {
			maxprenode->link = maxnode->link;
			p->link = maxnode;
			maxnode->link = NULL;
			break;
		}
	}
 }



//β�巨�����崴������
void CreateListR(LinkNode*& L, datatype* a, int n) {
	LinkNode* s, * tc;
	int i;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		tc->link = s;
		tc = s;
	}
	tc->link = NULL;
}
int main() {
	LinkNode* L;
	int i = 0, arr[100], x;
	InitList(L);
	while (1) {
		cin >> x;
		if (x == -1)
			break;
		arr[i++] = x;
	}
	CreateListR(L, arr, i);
	MovemaxNode(L);
	DispList(L);
}
