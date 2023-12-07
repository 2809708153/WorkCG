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

//先序遍历
void PreOrder(BTNode* bt) {
    if (bt) {
        printf("%c", bt->data);
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

//由二叉树中后序遍历序列，求前序遍历序列。a,b为中后序遍历序列数组，n为结点数
//在之前的由二叉树中后序遍历序列，求先序遍历序列。
void CreateInPostOrder(char* a, char* b , BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = b[n-1];   //将当前b数组的尾字符作为根
    (*bt) = (BTNode*)malloc(sizeof(BTNode));
    (*bt)->data = root;
    (*bt)->lchild = NULL;
    (*bt)->rchild = NULL;
    for (k = 0; k < n; k++)
        if (a[k] == root)
            break;
    //中序的每个层次的根节点的两边是左右(先左后右)孩子节点，分治
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
