#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
#define MaxSize 1000
typedef int ElemType;
//栈定义
typedef struct {
	ElemType data[MaxSize];
	int top;	/*栈指针*/
} SqStack;
//初始化栈
void InitStack(SqStack*& s) {
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}
//判断栈为空
int StackEmpty(SqStack* s) {
	return s->top == -1;
}
//进栈
int Push(SqStack*& s, ElemType e) {
	if (s->top == MaxSize - 1)    //栈满的情况
		return 0;
	s->top++;
	s->data[s->top] = e;
	return 1;
}
//出栈
int Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)		//栈为空的情况
		return 0;
	e = s->data[s->top];
	s->top--;
	return 1;
}
int GetTop(SqStack* s, ElemType& e) {
	if (s->top == -1) 		//栈为空的情况，即栈下溢出
		return 0;
	e = s->data[s->top];
	return 1;
}

//链队定义
typedef struct DataNode {
	ElemType data;
	struct DataNode* next;
} DataNode;				//链队数据结点类型
typedef struct {
	DataNode* front;
	DataNode* rear;
} LinkQuNode;			//链队类型
//初始化链队
void InitQueue(LinkQuNode*& q) {
	q = (LinkQuNode*)malloc(sizeof(LinkQuNode));
	q->front = q->rear = NULL;
}
//判断队空
int QueueEmpty(LinkQuNode* q) {
	return q->rear == NULL;
}
//进队
void enQueue(LinkQuNode*& q, ElemType e) {
	DataNode* p;
	p = (DataNode*)malloc(sizeof(DataNode));
	p->data = e;
	p->next = NULL;
	if (q->rear == NULL)		//若链队为空,则新结点是队首结点也是队尾结点
		q->front = q->rear = p;
	else {
		q->rear->next = p;	    //将p结点链到队尾,并将rear指向它
		q->rear = p;
	}
}
//出队
int deQueue(LinkQuNode*& q, ElemType& e) {
	DataNode* t;
	if (q->rear == NULL)		//队列为空
		return 0;
	t = q->front;				//t指向第一个数据结点
	if (q->front == q->rear)    //队列中只有一个结点时
		q->front = q->rear = NULL;
	else					    //队列中有多个结点时
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