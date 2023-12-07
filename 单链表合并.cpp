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
//输出链表
void DispList(SLinkNode* L) {
	SLinkNode* p = L->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//二路归并
void Merge(SLinkNode* ha, SLinkNode* hb, SLinkNode*& hc) {
	SLinkNode* pa = ha->next, * pb = hb->next, * tc;
	hc = ha;
	tc = hc;
	int i = 1;
	while (pa != NULL && pb != NULL) {
		if (i&1) {
			tc->next = pa;
			tc = pa;
			pa = pa->next;
		}
		else {
			tc->next = pb;
			tc = pb;
			pb = pb->next;
		}
		i++;
	}
	tc->next = NULL;
	if (pa != NULL)
		tc->next = pa;
	if (pb != NULL)
		tc->next = pb;
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


int main() {
	SLinkNode* L1, * L2, * L3;
	int i = 0, arr[100];
	char c;
	InitList(L1);
	InitList(L2);
	InitList(L3);
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	int len = i;
	CreateListR(L1, arr, len);        //尾插法创建L1
	i = 0;
	do {
		cin >> arr[i++];
	} while ((c = getchar()) != '\n');
	len = i;
	CreateListR(L2, arr, len);        //尾插法创建L2
	cout << "L1: ";
	DispList(L1);
	cout << "L2: ";
	DispList(L2);
	cout << "L1和L2合并后：" << endl;
	cout << "L1: ";
	DispList(L1);
	cout << "L2: ";
	DispList(L2);
	Merge(L1, L2, L3);                //归并
	cout << "L3: ";
	DispList(L3);
	return 0;
}



/*法二
#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node* next;
}Node;
//初始化 
Node* init()
{
	Node* head = (Node*)malloc(sizeof(Node));
	head->next = NULL;
	return head;
}
//输入线性表 
Node* creat(Node* head)  
{
	int a;
	Node* p = head;
	//尾插法
	char c = ' ';    //以换行作为结束
	while (c != '\n')
	{
		scanf("%d", &a);
		Node* pre = (Node*)malloc(sizeof(Node));
		pre->next = NULL;
		pre->data = a;
		p->next = pre;
		p = pre;
		c = getchar();
	}
	return head;
}
//求两集合并集
Node* comb(Node* headA, Node* headB)
{
	Node* pa = headA->next;
	Node* pb = headB->next;
	Node* newpc = (Node*)malloc(sizeof(Node));
	Node* pc = newpc;//将a、b的数据保存到新的线性表c中
	int i = 0;
	while (pa != NULL && pb != NULL)
	{

		Node* s = (Node*)malloc(sizeof(Node));

		if (i % 2 == 0)
		{
			s->data = pa->data;
			pc->next = s;
			pa = pa->next;
			pc = pc->next;
		}
		else if (i % 2 != 0)
		{
			s->data = pb->data;
			pc->next = s;
			pb = pb->next;
			pc = pc->next;
		}
		i++;
	}
	//若线性表A、B长度不等
	if (pa != NULL)
	{
		pc->next = pa;
	}
	else if (pb != NULL)
	{
		pc->next = pb;
	}
	pc = pc->next;
	return newpc;
}
//输出线性表
void output(Node* head)
{
	Node* p = head->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	Node* LA;
	Node* LB;
	Node* LC;
	//int a, b;
	//scanf("%d %d", &a, &b);//线性表ab的长度
	LA = init();
	LB = init();
	LA = creat(LA);
	LB = creat(LB);
	printf("L1：");
	output(LA);
	printf("L2：");
	output(LB);
	printf("L1和L2合并后：\n");
	printf("L1：");
	output(LA);
	printf("L2：");
	output(LB);
	LC = comb(LA, LB);
	printf("L3：");
	output(LC);
	return 0;
}
*/