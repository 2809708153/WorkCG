#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dot {
private: 
    int a, b;
public:
    void setxy(int x, int y) {  //可改为构造函数，定义类时自动调用
        a = x;
        b = y;
    }
    void displayxy() {
        cout << "(" << a << "," << b << ")" << endl;
    }
};

int main(){
    dot first, second;
    first.setxy(3, 4);
    second.setxy(5, 6);
    cout << "The first point is:";
    first.displayxy();
    cout << "The second point is:";
    second.displayxy();
    return 0;
}
