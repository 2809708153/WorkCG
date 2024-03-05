#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h> //万能头文件
using namespace std;

class Circle {
private:  //私有成员数据，该语句可省略
    int Radius1, Radius2;
public:
    void GetArea(int a) {  //此类函数可在类中定义，后再外部编写 函数类型 类名::函数名等等
        Radius1 = a;
        double res = 3.14 * Radius1 * Radius1;
        cout << "the circle is created!\n" << "the area is:";
        printf("%g", res);
    }
    void GetArea(int a, int b) {
        Radius1 = a;
        Radius2 = b;
        double res = 3.14 * Radius1 * Radius1 - 3.14 * Radius2 * Radius2;
        cout << "the circle is created!\n" << "the ring's area is:";
        printf("%g", res); //%g格式化输出自动忽略0
    }
};
int main(){
    Circle circle; 
    int arr[2], i = 1, a, b;
    char c;
    scanf("%d", &a);
    arr[0] = a;
    c = getchar(); //判断键盘输入是否含有空格，若有则代表输入两个数据
    if (c == ' ') {
        scanf("%d", &b);
        arr[1] = b;
        i = 2;
    }
    switch (i) {
    case 1:
        circle.GetArea(arr[0]); 
        break;
    case 2:
        circle.GetArea(arr[0], arr[1]);
        break;
    }
    return 0;
}