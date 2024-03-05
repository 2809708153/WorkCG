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
void MovemaxNode(LinkNode*& L, int& ma) {
	//�ֱ��ǵ�ǰ��㣬����㣬������ǰһ��㣬��ǰ������һ���
	LinkNode* p = L->link->link, * maxnode = L->link, * maxprenode = L, * pre = L->link;
	ma = pre->data;
	while (p) {
		if (p->data > maxnode->data) {
			maxnode = p;
			maxprenode = pre;
			ma = maxnode->data;
		}
		p = p->link;
		pre = pre->link;
	}
	maxprenode->link = maxnode->link;
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
	int i = 0, arr[100];
	InitList(L);
	int n;
	cin >> n;
	while (n--)
		cin >> arr[i++];
	CreateListR(L, arr, i);
	cout << "before delete max:";
	DispList(L);
	int ma = -1;
	MovemaxNode(L, ma);
	cout << "after delete max:";
	DispList(L);
	cout << "max=" << ma;
	system("pause");
	return 0;
}
