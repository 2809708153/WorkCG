#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("int.c", "r");
    if (file == NULL) {
        printf("�޷����ļ�");
        return 1;
    }
    char line[1000];             //��ȡһ��
    int varnum = 0;              //��¼���б�������
    char varstring[11][20];      //��������
    int vararr[11] = { 0 };      //�ж��Ƿ�ʹ��
    char t[21];
    int temp = 0;
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        int flag = 0;   //�жϸ����Ƿ�Ϊ���������
        while (line[i] != '\n') {
            if (isalpha(line[i]))
                t[temp++] = line[i];
            else if (!isalpha(line[i]) || line[i + 1] == '\n') {
                t[temp] = '\0';
                if (!strcmp(t, "int")) {
                    flag = 1;
                    strcpy(t, "          ");
                    temp = 0;
                    continue;
                }  
                if (flag == 1 && (int)strlen(t) != 0) {
                    strcpy(varstring[varnum], t);
                    strcpy(t, "          ");
                    temp = 0;
                    varnum++;
                }
                else {
                    int k = varnum, j;
                    for (j = 0; j < varnum; j++) {
                        if (!strcmp(varstring[j], t))
                            k = j;
                    }
                    if (k != varnum)
                        vararr[k] = 1;
                    strcpy(t, "          ");
                    temp = 0;
                }
            }
            i++;
        } 
    }
    int i;
    for (i = 0; i < varnum; i++) {
        if (!vararr[i])
            printf("%s\n", varstring[i]);
    }
    fclose(file);
    return 0;
}