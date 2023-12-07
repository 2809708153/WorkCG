#include <iostream>
#include <stdio.h>
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
//取栈顶元素
int GetTop(SqStack* s, ElemType& e) {
	if (s->top == -1) 		//栈为空的情况，即栈下溢出
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