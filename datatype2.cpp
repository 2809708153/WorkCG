#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Datatype {
    int i = 0;
    float f = 0;
    char c = 0;  //设置私有成员并赋初值
public:
    //重载构造函数，根据参数数据类型调用
    Datatype(int x) {
        i = x;
    }
    Datatype(char y) {
        c = y;
    }
    Datatype(float z) {
        f = z;
    }
    void print() {
        if (i) //判断哪个私有数据被更改
            cout << "int:" << i;
        else if (c)
            cout << "character:" << c;
        else
            cout << "float:" << f;
    }
};
int main()
{
    int k;
    cin >> k; //判断输入类型，以下不可用switch语句
    if (k == 1) {
        int i;
        cin >> i;
        Datatype datatype1(i);
        datatype1.print();
    }
    else if (k == 2) {
        char c;
        cin >> c;
        Datatype datatype2(c);
        datatype2.print();
    }
    else {
        float f;
        cin >> f;
        Datatype datatype3(f);
        datatype3.print();
    }
    return 0;
}