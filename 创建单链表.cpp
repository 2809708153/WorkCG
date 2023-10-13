#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef  int  ElemType;              /*假定线性表元素的类型为整型*/
#define  MaxSize  100          /*假定线性表的最大长度为1024*/

typedef  struct  LNode {   //定义单链表节点类型
	ElemType  data;
	struct  LNode* link;  //指向后继节点
}LinkList;  //链表类型



//头插法创建链表
void CreateListF(LinkList*& L, ElemType* a, int n) {
	LinkList* s;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->link = NULL;
	for (i = 0; i < n; i++) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->link = L->link;
		L->link = s;
	}
}
//尾插法创建单链表 
void CreateListR(LinkList*& L, ElemType* a, int n) {
	LinkList* s, * tc;
	int i; 
	L = (LinkList*)malloc(sizeof(LinkList));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		tc->link = s;
		tc = s;
	}
	tc->link = NULL;
}

//输出链表
void DispList(LinkList* L) {
	LinkList* p = L->link;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}
int main() {
	LinkList* L;
	int x, n, i;
	int arr[100];
	cin >> x >> n;
	if (!n) {
		cout << "list is empty!" << endl;
		return 0;
	}
	for (i = 0; i < n; i++)
		cin >> arr[i];
	if (x == 1)
		CreateListF(L, arr, n);
	else
		CreateListR(L, arr, n);
	DispList(L);
	system("pause");
	return 0;
}