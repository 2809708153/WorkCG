#include <iostream>
#include <stdio.h>
using namespace std;
#define MaxSize 1000
typedef char ElemType;

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
//ȡջ��Ԫ��
int GetTop(SqStack* s, ElemType& e) {
	if (s->top == -1) 		//ջΪ�յ��������ջ�����
		return 0;
	e = s->data[s->top];
	return 1;
}

int Match(SqStack*& lq,char *str,int len) {
	int i;
	char x;
	for (i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			Push(lq, str[i]);
		if (StackEmpty(lq))
			Push(lq, str[i]);
		else {
			if (str[i] == ')') {
				if (!StackEmpty(lq)){
					GetTop(lq, x);
					if (x == '(')
						Pop(lq, x);
					else
						return 0;
				}
			}
			else if (str[i] == ']') {
				if (!StackEmpty(lq)){
					GetTop(lq, x);
					if (x == '[')
						Pop(lq, x);
					else
						return 0;
				}
			}
			else if (str[i] == '}') {
				if (!StackEmpty(lq)){
					GetTop(lq, x);
					if (x == '{')
						Pop(lq, x);
					else
						return 0;
				}
			}
		}
	}
	return StackEmpty(lq);
}
int main() {
	SqStack* lq;
	InitStack(lq);
	char c, str[100];
	int i = 0;
	while ((c = getchar()) != '\n') {
		if (c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c=='}')
			str[i++] = c;
	}
	int len = i;
	int res = Match(lq, str, len);
	cout << res << endl;
	return 0;
}