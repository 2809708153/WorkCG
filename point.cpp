#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class dot {
private: 
    int a, b;
public:
    void setxy(int x, int y) {  //�ɸ�Ϊ���캯����������ʱ�Զ�����
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
