#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void value(int a, int b, int* sum, int* pro){ //接受指针参数，使得函数内可以改变外部变量的值
    *sum = a + b;
    *pro = a * b;
}

int main(){
    int a, b, s, p;
    scanf("%d%d", &a, &b);
    value(a, b, &s, &p);
    printf("%d %d", s, p);
    return 0;
}