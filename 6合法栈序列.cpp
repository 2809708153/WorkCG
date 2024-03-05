#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define MaxSize 1000
typedef char ElemType;

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
	s->data[++s->top] = e;
	return 1;
}
//出栈
int Pop(SqStack*& s, ElemType& e) {
	if (s->top == -1)		//栈为空的情况
		return 0;
	e = s->data[s->top--];
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
	char ch;
	int flag = 1;
	char s[1000];
	int i = 0;
	while ((ch = getchar()) != '\n') {
		s[i++] = ch;
		if (ch == 'I') {
			if (!Push(lq, ch))
				cout << "error" << " ";
		}
		else if (ch == 'O') {
			if (!Pop(lq, ch))
				flag = 0;
		}
	}
	s[i++] = '\0';
	if (flag && StackEmpty(lq))
		cout << s << " is the sequence of legal operations!";
	else
		cout << s << " is the sequence of illegal operations!";
	system("pause");
	return 0;
}