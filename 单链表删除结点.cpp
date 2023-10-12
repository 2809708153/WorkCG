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
//尾插法，整体创建链表
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
//输出链表
void DispList(SLinkNode* L) {
	SLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void Delminmax(SLinkNode*& L, int a, int b) {
	SLinkNode* p = L->next, * pre = L;
	while (p != NULL) {
		if (p->data >= a && p->data <= b) {
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
	SLinkNode* L;
	int i = 0, arr[100];
	char c;
	InitList(L);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len = i;
	CreateListR(L, arr, len);        //尾插法创建L1
	int a, b;
	cin >> a >> b;
	cout << "L: ";
	DispList(L);
	cout << "删除" << a << "～" << b << "的结点" << endl;
	Delminmax(L, a, b);
	cout << "L: ";
	DispList(L);
	return 0;
}