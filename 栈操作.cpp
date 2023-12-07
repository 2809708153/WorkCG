#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

int main() {
	SqStack* lq;
	InitStack(lq);
	int flag = 1, x;
	while (flag != -1) {
		cin >> flag;
		if (flag == 1) {
			cin >> x;
			if (!Push(lq, x))
				cout << "error" << " ";
		}
		else if (flag == 0) {
			if (!Pop(lq, x))
				cout << "error" << " ";
			else
				cout << x << " ";
		}
	}
	system("pause");
	return 0;
}