#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

//�ȽϺ�������������
int compare(const void* a, const void* b) {
    return strcmp((const char*)a, (const char*)b);
}

int main() {
    //����������ļ�
    FILE* inputFile = fopen("sort.in", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }
    FILE* outputFile = fopen("sort.out", "w");
    //��ȡ����
    char word[MAX_WORD_LENGTH];
    char words[MAX_WORD_LENGTH][MAX_WORD_LENGTH];
    int wordCount = 0;
    while (fscanf(inputFile, "%s", word) != EOF) {
        strcpy(words[wordCount++], word);
    }
    // �Ե��ʽ�������
    qsort(words, wordCount, sizeof(words[0]), compare);
    //ȥ��
    int i, j;
    for (i = 0, j = 1; j < wordCount; j++) {
        if (strcmp(words[i], words[j]) != 0) {
            i++;
            strcpy(words[i], words[j]);
        }
    }
    wordCount = i + 1;
    //д������ļ�
    for (i = 0; i < wordCount; i++) {
        fprintf(outputFile, "%s ", words[i]);
    }
    //�ر��ļ�
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}