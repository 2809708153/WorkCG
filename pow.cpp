#define _CRT_SECURE_NO_WARNINGS  1
//#pragma warning(disable:6031)
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> //�ɸ�Ϊ#include <string.h>
using namespace std;

double myPower(double x, int n) {
	double res = 1.0;
	int i;
	for (i = 0; i < n; i++) res *= x;
	return res;
}
/*
����string������������ü��ɣ�39�У�
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
	scanf("%d", &type); //ȷ������
	getchar(); //���ջ������Ļ���
	switch (type) {
	case 1: 
		scanf("%lf%d", &a, &n);
		printf("%g", myPower(a, n)); //%g�����Զ����Ը����������0
		break;
	case 2:
		scanf("%c%d", &c, &n);
		cout << myPower(c, n);  //����string����myPower(c, n)��
		break;
	}
	return 0;
}