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
    scanf("%s %c", str, &ch);  //ע�Ȿ��Ŀո�scanf�мӿո�����̱��뽫���ý�ȥ
    //����һ�пɸ�Ϊ���¼���
    //scanf("%s",str);  
    //getchar();  ����������scanf�����ո����tab���߻��л��Զ��Ͽ����˷���������ӱ������ѻ��л�ո��뵽����ch�в����߼����󣨲��׷��֣�
    //scanf("%c",&ch);
    //����Ҳ���Ըĳ�ѭ������
    //char s; int k=0;
    //while ((s=getchar())!=' ') str[k++]=s; 
    findchar(str, ch);
    return 0;
}