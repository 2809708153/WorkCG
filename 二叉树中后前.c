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
void PreOrder(BTNode* bt) {
    if (bt) {
        printf("%c", bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//�ɶ������к���������У���ǰ��������С�a,bΪ�к�������������飬nΪ�����
//��֮ǰ���ɶ������к���������У�������������С�
void CreateInPostOrder(char* a, char* b , BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = b[n-1];   //����ǰb�����β�ַ���Ϊ��
    (*bt) = (BTNode*)malloc(sizeof(BTNode));
    (*bt)->data = root;
    (*bt)->lchild = NULL;
    (*bt)->rchild = NULL;
    for (k = 0; k < n; k++)
        if (a[k] == root)
            break;
    //�����ÿ����εĸ��ڵ������������(�������)���ӽڵ㣬����
    CreateInPostOrder(a, b, &((*bt)->lchild), k);
    CreateInPostOrder(a + k + 1, b + k, &((*bt)->rchild), n - k - 1);
}

int main() {
    BTNode* bt;
    char a[1000], b[1000];
    scanf("%s%s", a, b);
    int n = (int)strlen(a);
    CreateInPostOrder(a, b, &bt, n);
    PreOrder(bt);
    return 0;
}
