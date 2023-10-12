#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define MaxSize 1000
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
//链表反转
void Reverse(SLinkNode*& L) {
	SLinkNode* p = L->next, * q;
	L->next = NULL;
	while (p != NULL) {
		q = p->next;
		p->next = L->next;
		L->next = p;
		p = q;
	}
}
/*int main() {
	
	SLinkNode* L;
	int i = 0, arr[10000];
	char c;
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len = i;
	if (len == 0) {
		cout<<"原链表为："<<endl;
		cout << "空链表！" << endl;
		cout << "逆置后的链表为：" << endl;
		cout << "空链表！" << endl;
		return 0;
	}
	CreateListR(L, arr, len);        //尾插法创建L
	cout << "原链表为：" << endl;
	DispList(L);
	Reverse(L);
	cout << "逆置后的链表为：" << endl;
	DispList(L);
	return 0;
}*/
int main() {
	char str[10000];
	int i;
	cin.getline(str, 10000);
	if (strlen(str) == 0) {
		cout << "原链表为：" << endl;
		cout << "空链表！" << endl;
		cout << "逆置后的链表为：" << endl;
		cout << "空链表！" << endl;
		return 0;
	}
	else {
		int len = (int)strlen(str);
		cout << "原链表为：" << endl;
		for (i = 0; i < len; i++)
			cout << str[i];
		cout << endl;
		for (i = 0; i < len-1; i++) {
			if (str[i] != ' ' && str[i + 1] != ' ') {
				char t = str[i];
				str[i] = str[i + 1];
				str[i + 1] = t;
			}
		}
		cout << "逆置后的链表为：" << endl;
		for (i = len - 1; i > -1; i--) {
			if (i == len - 1 && str[i] == ' ')
				continue;
			cout << str[i];
		}
		cout << endl;
	}
}