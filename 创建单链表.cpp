#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef  int  ElemType;              /*�ٶ����Ա�Ԫ�ص�����Ϊ����*/
#define  MaxSize  100          /*�ٶ����Ա����󳤶�Ϊ1024*/

typedef  struct  LNode {   //���嵥����ڵ�����
	ElemType  data;
	struct  LNode* link;  //ָ���̽ڵ�
}LinkList;  //��������



//ͷ�巨��������
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
//β�巨���������� 
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

//�������
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