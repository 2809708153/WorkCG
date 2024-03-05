#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class car; //提前说明car为类
class boat {
    float weight; 
public:
    boat(float w) { 
        weight = w;
    }
    friend float totalweight(boat &b, car &c); //在类中声明友元函数
};

class car {
    float weight; 
public:
    car(float w) { 
        weight = w;
    }
    friend float totalweight(boat &b, car &c); 
};
//友元函数
float totalweight(boat &b, car &c) {
    return b.weight + c.weight; 
}
int main() {
    float boatweight, carweight;
    cin >> boatweight >> carweight;
    boat b(boatweight);
    car c(carweight);
    cout << totalweight(b, c);
    return 0;
}