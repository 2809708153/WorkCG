#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class car; //��ǰ˵��carΪ��
class boat {
    float weight; 
public:
    boat(float w) { 
        weight = w;
    }
    friend float totalweight(boat &b, car &c); //������������Ԫ����
};

class car {
    float weight; 
public:
    car(float w) { 
        weight = w;
    }
    friend float totalweight(boat &b, car &c); 
};
//��Ԫ����
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