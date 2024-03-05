#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Cat {
    int age;
    static int HowManyCats; //静态数据
public:
    Cat(int a = 0) : age(a) {
        HowManyCats++;
    }
    ~Cat() {
        HowManyCats--;
        cout << "destructing of the cat!" << endl;
    }
    static int GetHowMany() {
        return HowManyCats;
    }
};

int Cat::HowManyCats = 0; //静态数据需在类外赋值

void creating() {
    cout << "before the Cat array is created,the number of the cat is:" << Cat::GetHowMany() << endl;
    Cat* pts[5];
    for (int i = 0; i < 5; i++) {
        pts[i] = new Cat(i + 1);
    }
    cout << "after the Cat array is created,the number of the cat is:" << Cat::GetHowMany() << endl;
    for (int i = 0; i < 5; i++) {
        delete pts[i];
    }
}

int main() {
    cout << "before the function,the number of the cat is:" << Cat::GetHowMany() << endl;
    creating();
    cout << "after the function,the number of the cat is:" << Cat::GetHowMany() << endl;
    return 0;
}