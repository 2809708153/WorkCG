#include <iostream>
#include <stdlib.h>
using namespace std;

class BaseClass { //»ùÀà(¸¸Àà)
public:
	void fn1() {
		cout << "the fn1 founction of the baseclass" << endl;
	}
	void fn2() {
		cout << "the fn2 founction of the baseclass" << endl;
	}
};
class DerivedClass :public BaseClass {
public:
	void fn1() {
		cout << "the fn1 founction of the DerivedClass" << endl;
	}
	void fn2() {
		cout << "the fn2 founction of the DerivedClass" << endl;
	}
};
int main() {
	DerivedClass derivedclass;
	derivedclass.fn1();
	derivedclass.fn2();
	BaseClass* p1 = new DerivedClass;
	p1->fn1();
	p1->fn2();
	DerivedClass* p2 = new DerivedClass;
	p2->fn1();
	p2->fn2();
	/*delete p1, p2;*/
	system("pause");
	return 0;
}