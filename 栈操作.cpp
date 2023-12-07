#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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