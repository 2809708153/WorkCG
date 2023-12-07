#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
#define MaxSize 1000
typedef int ElemType;
//ջ����
typedef struct {
	ElemType data[MaxSize];
	int top;	/*ջָ��*/
} SqStack;
//��ʼ��ջ
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//�ж�ջΪ��
int StackEmpty(SqStack* s) {
	return s->top == -1;
}
//��ջ
int Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)    //ջ�������
		return 0;
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//��ջ
int Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)		//ջΪ�յ����
		return 0;
	e = s->data[s->top];
	s->top--;
	return 1;
}
int GetTop(SqStack* s, ElemType& e) {
	if (s->top == -1) 		//ջΪ�յ��������ջ�����
		return 0;
	e = s->data[s->top];
	return 1;
}

//���Ӷ���
typedef struct DataNode {
	ElemType data;
	struct DataNode* next;
} DataNode;				//�������ݽ������
typedef struct {
	DataNode* front;
	DataNode* rear;
} LinkQuNode;			//��������
//��ʼ������
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//�ж϶ӿ�
int QueueEmpty(LinkQuNode* q) {
	return q->rear == NULL;
}
//����
void enQueue(LinkQuNode*& q, ElemType e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)		//������Ϊ��,���½���Ƕ��׽��Ҳ�Ƕ�β���
		q->front = q->rear = p;
	else {
		q->rear->next = p;	    //��p���������β,����rearָ����
		q->rear = p;
	}
}
//����
int deQueue(LinkQuNode*& q, ElemType& e) {
	DataNode* t;
	if (q->rear == NULL)		//����Ϊ��
		return 0;
	t = q->front;				//tָ���һ�����ݽ��
	if (q->front == q->rear)    //������ֻ��һ�����ʱ
		q->front = q->rear = NULL;
	else					    //�������ж�����ʱ
		q->front = q->front->next;
	e = t->data;
	free(t);
	return 1;
}


int main() {
	SqStack* sq;
	InitStack(sq);
	LinkQuNode* lq;
	InitQueue(lq);
	int n, x, i, e;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x;
		enQueue(lq, x);
	}
	while (!QueueEmpty(lq)) {
		deQueue(lq, e);
		Push(sq, e);
	}
	while (!StackEmpty(sq)) {
		Pop(sq, e);
		cout << e << " ";
	}
	system("pause");
	return 0;
}