#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int findsum(int* in, int len, int sum) {
    int i, j;
    for (i = 0, j = len - 1; i < j; ) {
        if (in[i] + in[j] == sum) {
            printf("%d %d", in[i], in[j]);
            return 1;
        }
        else if (in[i] + in[j] < sum)
            i++;
        else
            j--;
    }
    printf("no answer");
    return 0;
}

int main() {
    int arr[1000], i = 0;
    char ch;
    while (1) {
        scanf("%d", arr + i);
        i++;
        ch = getchar();
        if (ch == '\n')
            break;
    }
    int k;
    scanf("%d", &k);
    findsum(arr, i, k);
    return 0;
}