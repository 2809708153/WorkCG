#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//文件操作
FILE* input, * output;
//本题根据题意如果得出最短的步骤，那么有唯一解但根据测试数据的期望输出可以看出不是
//求最有情况，而洛谷上面有类似题是求最优情况、力扣上面是判断所给数据能否实现操作，
//并且对于本题中所给答案中3 5 4数据有两个不同答案，如下是一个实现方案，优于系统答
//案（执行步骤更少）
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