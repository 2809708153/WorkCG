#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

//比较函数，用于排序
int compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main() {
    //打开输入输出文件
    FILE* inputFile = fopen("sort.in", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }
    FILE* outputFile = fopen("sort.out", "w");
    //读取单词
    char word[MAX_WORD_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(inputFile, "%s", word) != EOF) {
        strcpy(words[wordCount++], word);
    }
    // 对单词进行排序
    qsort(words, wordCount, sizeof(words[0]), compare);
    //去重
    int i, j;
    for (i = 0, j = 1; j < wordCount; j++) {
        if (strcmp(words[i], words[j]) != 0) {
            i++;
            strcpy(words[i], words[j]);
        }
    }
    wordCount = i + 1;
    //写入输出文件
    for (i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s ", words[i]);
    }
    //关闭文件
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}