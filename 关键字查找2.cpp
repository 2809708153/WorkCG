#include <stdio.h>

int main() {
    char program[300];
    fgets(program, sizeof(program), stdin);
    int i = 0;
    int position = 1;   //记录位置 
    while (program[i] != '\0') { 
        // 判断是否为关键字的起始位置（关键字的后面为空格或者'('）
        if (program[i] == 'w' && program[i + 1] == 'h' && program[i + 2] == 'i' && program[i + 3] == 'l' && program[i + 4] == 'e' && (program[i + 5] == ' ' || program[i + 5] == '('))
            printf("while:%d\n", position);
        else if (program[i] == 'f' && program[i + 1] == 'o' && program[i + 2] == 'r' && (program[i + 3] == ' ' || program[i + 3] == '('))
            printf("for:%d\n", position);
        else if (program[i] == 'i' && program[i + 1] == 'f' && (program[i + 2] == ' ' || program[i + 2] == '('))
            printf("if:%d\n", position);
        if (program[i] == '\n')
            break;
        if (program[i] == '\"') {   //跳过字符串常量，按position需要累加
            i++;
            position++;
            while (program[i] != '\"') {
                if (program[i] == '\0' || program[i] == '\n')
                    break;
                i++;
                position++;
            }
        }
        i++;
        position++;
    }
    return 0;
}