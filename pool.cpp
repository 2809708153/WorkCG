#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926

class Circle {
    double radius;  
public:
    Circle(double r) {
        radius = r;
    }
    double getRadius() {
        return radius;
    } 
    double getPerimeter() {
        return 2 * PI * radius;
    } //计算周长
    double getArea() {
        return PI * radius * radius;
    } //计算面积
};

double calculatePathCost(Circle* pool) {
    double pathWidth = 3;  //过道宽度
    Circle* path = new Circle(pool->getRadius() + pathWidth);  //创建过道对象
    double pathArea = path->getArea() - pool->getArea();  //计算过道面积
    double pathCost = pathArea * 20;  //计算过道造价
    delete path;  //释放过道对象
    return pathCost;
}

double calculateFenceCost(Circle pool) {
    double fenceLength = pool.getPerimeter() + 2 * PI * 3;  //栅栏长度就是过道外围周长周长
    double fenceCost = fenceLength * 35;  //计算栅栏造价
    return fenceCost;
}

int main() {
    double radius;
    cin >> radius;
    Circle pool(radius);  
    double pathCost = calculatePathCost(&pool);  //计算过道造价
    double fenceCost = calculateFenceCost(pool);  //计算栅栏造价
    cout << "the fencing cost is:" << fenceCost << endl;
    cout << "the concrete cost is:" << pathCost << endl;
    return 0;
}