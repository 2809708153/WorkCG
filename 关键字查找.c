#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    FILE* file = fopen("in.c", "r");
    if (file == NULL) {
        printf("无法打开文件");
            return 1;
    }
    char line[1000];
    int line_num = 1;
    
    while (fgets(line, sizeof(line), file)) {
        int i = 0;
        int position = 1;   //记录位置 
        while (line[i] != '\0') {
            // 判断是否为关键字的起始位置（关键字的后面为空格或者'('）
            if (line[i] == 'w' && line[i + 1] == 'h' && line[i + 2] == 'i' && line[i + 3] == 'l' && line[i + 4] == 'e' && (line[i + 5] == ' ' || line[i + 5] == '('))
                printf("while:%d,%d\n", line_num, position);
            else if (line[i] == 'f' && line[i + 1] == 'o' && line[i + 2] == 'r' && (line[i + 3] == ' ' || line[i + 3] == '('))
                printf("for:%d,%d\n", line_num, position);
            else if (line[i] == 'i' && line[i + 1] == 'f' && (line[i + 2] == ' ' || line[i + 2] == '('))
                printf("if:%d,%d\n", line_num, position);
            if (line[i] == '\n')
                break;
            if (line[i] == '\"') {   //跳过字符串常量，按position需要累加
                i++;
                position++;
                while (line[i] != '\"') {
                    if (line[i] == '\0' || line[i] == '\n')
                        break;
                    i++;
                    position++;
                }
            }
            i++;
            position++;
        }
        line_num++;
    }

    fclose(file);
    return 0;
}