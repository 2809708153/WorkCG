#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef int datatype;

typedef struct node {
    datatype data;
    node* link;
}LinkNode;

//初始化链表
void InitList(LinkNode*& L) {
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->link = NULL;
}
//销毁
void DestroyList(LinkNode*& L) {
	LinkNode* pre = L, * p = pre->link;
	while (p != NULL) {
		free(pre);
		pre = p;
		p = p->link;
	}
	free(pre);
}
//输出链表
void DispList(LinkNode* L) {
	LinkNode* p = L->link;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->link;
	}
	cout << endl;
}
//法一   解题思路：首先遍历链表，找到最大的那个点然后删除记录最大添加到末尾：
/*//删除最大结点
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
//法二   解题思路：对法一优化首先遍历链表，找到最大结点并记录最大的前一结点，然后改变指针指向：
void MovemaxNode(LinkNode*& L) {
	//分别是当前结点，最大结点，最大结点的前一结点，当前结点的上一结点
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



//尾插法，整体创建链表
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
