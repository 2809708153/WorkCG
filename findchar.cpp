#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void findchar(char* str, char ch){
    int len = strlen(str), i, flag = 0;
    for (i = 0; i < len; i++)
        if (*(str + i) == ch) {
            printf("%d ", i);
            flag = 1;
        }
    if (flag == 0)
        printf("NULL");
}

int main(){
    char str[30], ch;
    scanf("%s %c", str, &ch);  //注意本题的空格，scanf中加空格，则键盘必须将其敲进去
    //上面一行可改为以下几行
    //scanf("%s",str);  
    //getchar();  本行是由于scanf遇见空格或者tab或者换行会自动断开，此方法若不添加本句则会把换行或空格导入到变量ch中产生逻辑错误（不易发现）
    //scanf("%c",&ch);
    //上面也可以改成循环如下
    //char s; int k=0;
    //while ((s=getchar())!=' ') str[k++]=s; 
    findchar(str, ch);
    return 0;
}