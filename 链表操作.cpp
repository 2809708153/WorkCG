#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <iostream>
using namespace std;
typedef  int  ElemType;              /*�ٶ����Ա�Ԫ�ص�����Ϊ����*/
#define  MaxSize  100          /*�ٶ����Ա����󳤶�Ϊ1024*/

typedef  struct  LNode {   //���嵥����ڵ�����
	ElemType  data;
	struct  LNode* next;  //ָ���̽ڵ�
}LinkList;  //��������



//ͷ�巨��������
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
//ɾ�����
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
//�������
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