#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Mammal { //���ඨ�壬�����캯������������
public:
	Mammal() {
		cout << "Mammal constructor" << endl;
	}
	~Mammal() {
		cout << "Mammal destructor" << endl;
	}
};
class Dog :public Mammal { //���м̳�
public:
	Dog() {
		cout << "Dog constructor" << endl;
	}
	~Dog() {
		cout << "Dog destructor" << endl;
	}
	void speak() {
		cout << "wang wang" << endl;
	}
};
void creating() {
	Dog* p = new Dog(); //��̬����һ��ָ��Dog�����ָ��
	p->speak();
	delete p; //�ͷ�p
}
int main() {
	creating();
	system("pause");
	return 0;
}