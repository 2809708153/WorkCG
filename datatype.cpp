#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Datatype {
    int k;
    union Data {
        int i;
        char c;
        float f;
    }data;
public:
    Datatype(int x,int a) {
        data.i = x;
        k = a;
    }
    Datatype(char y,int a) {
        data.c = y;
        k = a;
    }
    Datatype(float z,int a) {
        data.f = z;
        k = a;
    }
    void print() {
        switch (k) {
        case 1:
            cout << "int:" << data.i;
            break;
        case 2:
            cout << "character:" << data.c;
            break;
        case 3:
            cout << "float:" << data.f;
            break;
        }
    }
};
int main()
{
    union Data {
        int i;
        float f;
        char c;
    }data;
    int k;
    cin >> k;
    if (k == 1) {
        cin >> data.i;
        Datatype datatype1(data.i, k);
        datatype1.print();
    }
    else if (k == 2) {
        cin >> data.c;
        Datatype datatype2(data.c, k);
        datatype2.print();
    }
    else {
        cin >> data.f;
        Datatype datatype3(data.f, k);
        datatype3.print();
    }
    return 0;
}