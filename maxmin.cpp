#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void max_min(float a[], int n, float* max, float* min){  //第一个参数可改为float *a
    int i;
    *max = *min = a[0]; //使两个指针指向数组首个元素
    for (i = 1; i < n; i++){ //从数组第二个开始比较
        if (a[i] > *max)
            *max = a[i];
        if (a[i] < *min)
            *min = a[i];
    }
}

int main(){
    float a[1000], max, min, * p = a;
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%f", (p + i)); //此处p+i相当于&a[i]
    max_min(a, n, &max, &min);
    printf("%.2f\n%.2f", max, min); 
    return 0;
}