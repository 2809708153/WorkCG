#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void value(int a, int b, int* sum, int* pro){ //����ָ�������ʹ�ú����ڿ��Ըı��ⲿ������ֵ
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