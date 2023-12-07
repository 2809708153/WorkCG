#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�ļ�����
FILE* input, * output;
//���������������ó���̵Ĳ��裬��ô��Ψһ�⵫���ݲ������ݵ�����������Կ�������
//����������������������������������������������������ж����������ܷ�ʵ�ֲ�����
//���Ҷ��ڱ�������������3 5 4������������ͬ�𰸣�������һ��ʵ�ַ���������ϵͳ��
//����ִ�в�����٣�
void pour(int ca, int cb, int a, int b, int n) {
    if (n == b) {
        fprintf(output, "Success\n");
        return;
    }
    if (a == 0) {
        fprintf(output, "Fill A\n");
        pour(ca, cb, ca, b, n);
    }
    else if (b == cb) {
        fprintf(output, "Empty B\n");
        pour(ca, cb, a, 0, n);
    }
    else if (a > 0 && b < cb) {
        int pourAmount = a < (cb - b) ? a : (cb - b);
        fprintf(output, "Pour A B\n");
        pour(ca, cb, a - pourAmount, b + pourAmount, n);
    }
}

int main() {
    int ca, cb, N;
    input = fopen("jugs.in", "r");
    output = fopen("jugs.out", "w");
    fscanf(input, "%d %d %d", &ca, &cb, &N);
    pour(ca, cb, 0, 0, N);
    return 0;
}