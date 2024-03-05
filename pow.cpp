#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> //可改为#include <string.h>
using namespace std;

double myPower(double x, int n) {
	double res = 1.0;
	int i;
	for (i = 0; i < n; i++) res *= x;
	return res;
}
/*
不用string方法，下面调用即可（39行）
void myPower(char x, int n) {
	int i;
	for (i = 0; i < n; i++) printf("%c", x);
}*/
string myPower(char x, int n) {    
	string res = "";
	int i;
	for (i = 0; i < n; i++) res += x;
	return res;
}
int main() {
	int type, n;
	double a;
	char c;
	scanf("%d", &type); //确认类型
	getchar(); //吸收缓冲区的换行
	switch (type) {
	case 1: 
		scanf("%lf%d", &a, &n);
		printf("%g", myPower(a, n)); //%g可以自动忽略浮点数后面的0
		break;
	case 2:
		scanf("%c%d", &c, &n);
		cout << myPower(c, n);  //不用string方法myPower(c, n)；
		break;
	}
	return 0;
}