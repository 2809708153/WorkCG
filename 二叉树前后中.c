#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100        //������󳤶�
typedef char ElemType;  //������������    

//�������������ʽ�洢�ṹ
typedef struct tnode {
    ElemType data;                    //������
    struct tnode* lchild, * rchild;   //ָ����
}BTNode;

//�������
void InOrder(BTNode* bt) {
    if (bt) {
        InOrder(bt->lchild);
        printf("%c", bt->data);
        InOrder(bt->rchild);
    }
}

//�ɶ���������ͺ���������У�������������С�a,bΪ�Ⱥ�������������飬nΪ�����
void CreatePrePostOrder(char* a, char* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = a[0];       //����ǰa��������ַ���Ϊ��
    (*bt) = (BTNode*)malloc(sizeof(BTNode));
    (*bt)->data = root;
    (*bt)->lchild = NULL;
    (*bt)->rchild = NULL;
    if (n == 1)
        return;
    for (k = 0; k < n; k++)
        if (b[k] == a[1])
            break;
    CreatePrePostOrder(a + 1, b, &((*bt)->lchild), k + 1);
    CreatePrePostOrder(a + k + 2, b + k + 1, &((*bt)->rchild), n - k - 2);
}

int main() {
    BTNode* bt;
    char a[1000], b[1000];
    scanf("%s%s", a, b);
    int n = (int)strlen(a);
    CreatePrePostOrder(a, b, &bt, n);
    InOrder(bt);
    return 0;
}