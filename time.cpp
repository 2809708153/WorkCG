
#include <bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int da = 0;
    for (int i = 0; i < 1000; i++) {
        double a = (rand() % 10) * 0.1;
        if (a >= 0.5)
            da++;
        /*cout << a << endl;

        if (a > 0.5)
            cout << "ด๓" << endl;
        else
            cout << "ะก" << endl;*/
    }
    double per = (double)da / 1000;
    cout << per;
    return 0;
}


