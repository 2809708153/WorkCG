#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Datatype {
    int i = 0;
    float f = 0;
    char c = 0;  //����˽�г�Ա������ֵ
public:
    //���ع��캯�������ݲ����������͵���
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
        if (i) //�ж��ĸ�˽�����ݱ�����
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
    cin >> k; //�ж��������ͣ����²�����switch���
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