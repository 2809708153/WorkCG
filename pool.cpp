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
    } //�����ܳ�
    double getArea() {
        return PI * radius * radius;
    } //�������
};

double calculatePathCost(Circle* pool) {
    double pathWidth = 3;  //�������
    Circle* path = new Circle(pool->getRadius() + pathWidth);  //������������
    double pathArea = path->getArea() - pool->getArea();  //����������
    double pathCost = pathArea * 20;  //����������
    delete path;  //�ͷŹ�������
    return pathCost;
}

double calculateFenceCost(Circle pool) {
    double fenceLength = pool.getPerimeter() + 2 * PI * 3;  //դ�����Ⱦ��ǹ�����Χ�ܳ��ܳ�
    double fenceCost = fenceLength * 35;  //����դ�����
    return fenceCost;
}

int main() {
    double radius;
    cin >> radius;
    Circle pool(radius);  
    double pathCost = calculatePathCost(&pool);  //����������
    double fenceCost = calculateFenceCost(pool);  //����դ�����
    cout << "the fencing cost is:" << fenceCost << endl;
    cout << "the concrete cost is:" << pathCost << endl;
    return 0;
}