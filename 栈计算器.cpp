#include <iostream>
#include <bits/stdc++.h> 
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

//法一，一个栈
int main() {
	SqStack* num;
	InitStack(num);
	int n, x, i = 0;
	string oper[100];
	cin >> n;
	while (n--) {
		//string opera;
		cin >> oper[i++] >> x;
		//oper[i++] = opera;
		Push(num, x);
		if (n == 0) {
			cin >> x;
			Push(num, x);
		}
	}
	int len = i, a = 0, b = 0;
	for (i = len - 1; i > -1; i--) {
		Pop(num, a);
		Pop(num, b);
		int res = 0;
		if (oper[i] == "Mul")
			res = a * b;
		else if (oper[i] == "Sub")
			res = a - b;
		else if (oper[i] == "Add")
			res = a + b;
		Push(num, res);
	}
	Pop(num, x);
	cout << x << endl;
	system("pause");
	return 0;
}
/*
//法二，用两个栈分别存放数字和运算符
int Calculator() {
	stack<int> num;
	stack<string> opers;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string operation;
		int number;
		cin >> operation >> number;
		num.push(number);
		opers.push(operation);
	}
	int first;
	cin >> first;
	num.push(first);
	while (!opers.empty()) {
		int a = num.top(); 
		num.pop();
		int b = num.top(); 
		num.pop();
		string c = opers.top(); 
		opers.pop();
		if (c == "Mul") 
			num.push(a * b);
		else if (c == "Add") 
			num.push(a + b);
		else if (c == "Sub") 
			num.push(a - b);
	}
	return(num.top());
}

int main(){
	cout << Calculator();
	return 0;
}

*/


