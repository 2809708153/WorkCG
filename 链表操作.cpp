#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef  int  ElemType;              /*假定线性表元素的类型为整型*/
#define  MaxSize  100          /*假定线性表的最大长度为1024*/

typedef  struct  LNode {   //定义单链表节点类型
	ElemType  data;
	struct  LNode* next;  //指向后继节点
}LinkList;  //链表类型



//头插法创建链表
void CreateListF(LinkList*& L, ElemType* a, int n) {
	LinkList* s;
	int i;
	L = (LinkList*)malloc(sizeof(LinkList));
	L->next = NULL;
	for (i = 0; i < n; i++) {
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}
//删除结点
void DelNode(LinkList*& L, int x) {
	LinkList* p = L->next, * pre = L;
	while (p != NULL) {
		if (p->data == x) {
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
//输出链表
void DispList(LinkList* L) {
	LinkList* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main() {
	LinkList* L;
	int x, i = 0;
	int arr[100];
	while (1) {
		cin >> x;
		if (x == -1)
			break;
		arr[i++] = x;
	}
	int len = i;
	CreateListF(L, arr, len);
	cin >> x;
	DelNode(L, x);
	DispList(L);
	system("pause");
	return 0;
}