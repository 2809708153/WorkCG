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
//ȡջ��Ԫ��
int GetTop(SqStack* s, ElemType& e) {
	if (s->top == -1) 		//ջΪ�յ��������ջ�����
		return 0;
	e = s->data[s->top];
	return 1;
}

int main() {
	SqStack* lq;
	InitStack(lq);
	char c, str[100];
	int x = 0, a = 0, b = 0, i = 0;
	while ((c = getchar()) != '\n')
		str[i++] = c;
	int len = i;
	for (i = 0; i < len - 1; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (str[i + 1] >= '0' && str[i + 1] <= '9') {
				x = (int(str[i]) - 48) * 10 + (int(str[i + 1]) - 48);
				Push(lq, x);
				i++;
			}
			else {
				x = int(str[i]) - 48;
				Push(lq, x);
			}
		}
		else if (str[i] == '+') {
			Pop(lq, a);
			Pop(lq, b);
			Push(lq, b + a);
		}
		else if (str[i] == '-') {
			Pop(lq, a);
			Pop(lq, b);
			Push(lq, b - a);
		}
		else if (str[i] == '*') {
			Pop(lq, a);
			Pop(lq, b);
			Push(lq, b * a);
		}
		else if (str[i] == '/') {
			Pop(lq, a);
			Pop(lq, b);
			Push(lq, b / a);
		}
	}
	GetTop(lq, x);
	cout << x << endl;
	system("pause");
	return 0;
}