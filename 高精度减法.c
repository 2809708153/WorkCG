#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<string.h>


int compare(char* a, char* b) {    //�жϴ�С
    int i;
    if (strlen(a) < strlen(b))
        return 0;
    else if (strlen(a) > strlen(b))
        return 1;
    for (i = 0; i < strlen(a); i++)
        if (a[i] < b[i])
            return 0;
    return 1;
}
void minus(char* a, char* b, char* c ,int k1, int k2) {
    int i;
    char k;
    for (i = 0; i < k1; i++, k1--) {   //��ת
        k = a[i];
        a[i] = a[k1];
        a[k1] = k;
    }
    for (i = 0; i < k2; i++, k2--) {   //��ת
        k = b[i];
        b[i] = b[k2];
        b[k2] = k;
    }
    for (i = 0; i < strlen(a); i++) {
        if (i >= strlen(b))
            c[i] = a[i] - '0';
        else
            c[i] = a[i] - b[i];
    }
    for (i = 0; i < strlen(a); i++)
        while (c[i] < 0) {
            c[i] += 10;
            c[i + 1] -= 1;
        }
}
int main(){
    int i, j, k1, k2;
    char a[100], b[100], c[100] = { 0 };
    scanf("%s", a);
    scanf("%s", b);
    k1 = strlen(a) - 1;
    k2 = strlen(b) - 1;
    if (compare(a, b)) {
        minus(a, b, c, k1, k2);
    }
    else {
        printf("-");
        minus(b, a, c, k2, k1);
    }
    i = 90;
    while (c[i] == 0 && i != 0) 
        i--;
    for (j = i; j >= 0; j--)
        printf("%d", c[j]);
    return 0;
}