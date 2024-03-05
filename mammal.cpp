#include <iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

class Mammal { //父类定义，含构造函数和析构函数
public:
	Mammal() {
		cout << "Mammal constructor" << endl;
	}
	~Mammal() {
		cout << "Mammal destructor" << endl;
	}
};
class Dog :public Mammal { //公有继承
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
	Dog* p = new Dog(); //动态生成一个指向Dog对象的指针
	p->speak();
	delete p; //释放p
}
int main() {
	creating();
	system("pause");
	return 0;
}