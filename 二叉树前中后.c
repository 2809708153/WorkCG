#define _CRT_SECURE_NO_WARNINGS  1
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

//后序遍历
void PostOrder(BTNode* bt) {
    if (bt) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        printf("%c", bt->data);
    }
}

//由二叉树前中序遍历序列，求后序遍历序列。a,b为前中序遍历序列数组，n为结点数
void CreatePreInOrder(char* a, char* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = a[0];   //将当前a数组的首字符作为根
    (*bt) = (BTNode*)malloc(sizeof(BTNode));
    (*bt)->data = root;
    (*bt)->lchild = NULL;
    (*bt)->rchild = NULL;
    for (k = 0; k < n; k++)
        if (b[k] == root)
            break;
    //中序的每个层次的根节点的两边是左右(先左后右)孩子节点，分治
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