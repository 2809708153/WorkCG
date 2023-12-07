#define _CRT_SECURE_NO_WARNINGS  1
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
void PostOrder(BTNode* bt) {
    if (bt) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%c", bt->data);
    }
}

//�ɶ�����ǰ����������У������������С�a,bΪǰ��������������飬nΪ�����
void CreatePreInOrder(char* a, char* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = a[0];   //����ǰa��������ַ���Ϊ��
    (*bt) = (BTNode*)malloc(sizeof(BTNode));
    (*bt)->data = root;
    (*bt)->lchild = NULL;
    (*bt)->rchild = NULL;
    for (k = 0; k < n; k++)
        if (b[k] == root)
            break;
    //�����ÿ����εĸ��ڵ������������(�������)���ӽڵ㣬����
    CreatePreInOrder(a + 1, b, &((*bt)->lchild), k);
    CreatePreInOrder(a + k + 1, b + k + 1, &((*bt)->rchild), n - k - 1);
}

int main() {
    BTNode* bt;
    char a[1000], b[1000];
    scanf("%s%s", a, b);
    int n = (int)strlen(a);
    CreatePreInOrder(a, b, &bt, n);
    PostOrder(bt);
    return 0;
}