#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000
typedef int ElemType;

//栈定义
typedef struct {
	ElemType data[MaxSize];
	int top;	/*栈指针*/
} SqStack;
//初始化栈
void InitStack(SqStack* s) {
	s->top = -1;
}
//进栈
int Push(SqStack* s, ElemType *e) {
	if (s->top == MaxSize - 1)    //栈满的情况
		return 0;
	s->top++;
	s->data[s->top] = *e;
	return 1;
}
//出栈
int Pop(SqStack* s, ElemType *e) {
	if (s->top == -1)		//栈为空的情况
		return 0;
	*e = s->data[s->top];
	s->top--;
	return 1;
}
//取栈顶元素
int GetTop(SqStack *s, ElemType *e) {
	if (s->top == -1) 		//栈为空的情况，即栈下溢出
		return 0;
	*e = s->data[s->top];
	return 1;
}

int main() {
	SqStack lq;
	InitStack(&lq);
	char c, str[100];
	int x = 0, a = 0, b = 0, i = 0;
	while ((c = getchar()) != '\n')
		str[i++] = c;
	int len = i, t = 0;
	for (i = 0; i < len - 1; i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (str[i + 1] >= '0' && str[i + 1] <= '9') {
				x = (str[i] - 48) * 10 + (str[i + 1] - 48);
				Push(&lq, &x);
				i++;
			}
			else {
				x = str[i] - 48;
				Push(&lq, &x);
			}
		}
		else if (str[i] == '+') {
			Pop(&lq, &a);
			Pop(&lq, &b);
			t = b + a;
			Push(&lq, &t);
		}
		else if (str[i] == '-') {
			Pop(&lq, &a);
			Pop(&lq, &b);
			t = b - a;
			Push(&lq, &t);
		}
		else if (str[i] == '*') {
			Pop(&lq, &a);
			Pop(&lq, &b);
			t = b * a;
			Push(&lq, &t);
		}
		else if (str[i] == '/') {
			Pop(&lq, &a);
			Pop(&lq, &b);
			t = b / a;
			Push(&lq, &t);
		}
	}
	GetTop(&lq, &x);
	printf("%d\n", x);
	system("pause");
	return 0;
}