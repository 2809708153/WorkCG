#include <iostream>
#include <stdlib.h>
using namespace std;

class Shape { //父类
public:
	virtual double GetArea() = 0; 
};
class Rectangle :public Shape {
	double width, height;
public:
	Rectangle(double x, double y) {
		width = x;
		height = y;
	}
	virtual double GetArea() {
		return width * height;
	}
};
class Circle :public Shape {
	double radius;
public:
	Circle(double x) {
		radius = x;
	}
	virtual double GetArea() {
		return 3.14 * radius * radius;
	}
};
class Square :public Rectangle {
public:
	Square(double x) :Rectangle(x, x) {}
};
int main() {
	Shape* p1 = new Circle(5); //动态生成三个指向不同对象的指针
	Shape* p2 = new Rectangle(4, 6);
	Shape* p3 = new Square(5);
	cout << "The area of the Cirele is:" << p1->GetArea() << endl;
	cout << "The area of the Recanale is:" << p2->GetArea() << endl;
	cout << "The area of the Recanale is:" << p3->GetArea() << endl;
	/*delete p1;
	delete p2;
	delete p3;*/  //释放空间
	system("pause");
	return 0;
}