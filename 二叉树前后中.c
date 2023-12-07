#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxSize 100        //定义最大长度
typedef char ElemType;  //定义数据类型    

//定义二叉树的链式存储结构
typedef struct tnode {
    ElemType data;                    //数据域
    struct tnode* lchild, * rchild;   //指针域
}BTNode;

//中序遍历
void InOrder(BTNode* bt) {
    if (bt) {
        InOrder(bt->lchild);
        printf("%c", bt->data);
        InOrder(bt->rchild);
    }
}

//由二叉树先序和后序遍历序列，求中序遍历序列。a,b为先后序遍历序列数组，n为结点数
void CreatePrePostOrder(char* a, char* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = a[0];       //将当前a数组的首字符作为根
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