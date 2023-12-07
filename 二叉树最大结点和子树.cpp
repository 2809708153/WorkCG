#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100        //定义最大长度
typedef int ElemType;  //定义数据类型    

//定义二叉树的链式存储结构
typedef struct tnode {
    ElemType data;                    //数据域
    struct tnode* lchild, * rchild;   //指针域
}BTNode;

//由二叉树前中序遍历序列，求后序遍历序列。a,b为前中序遍历序列数组，n为结点数
void CreatePreInOrder(int* a, int* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    int root = a[0];   //将当前a数组的首字符作为根
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
//先序遍历
void PreOrder(BTNode* bt) {
    if (bt) {
        cout << bt->data << "  ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}
//中序遍历
void InOrder(BTNode* bt) {
    if (bt != NULL) {
        InOrder(bt->lchild);
        cout << bt->data << "  ";
        InOrder(bt->rchild);
    }
}
//后序遍历
void PostOrder(BTNode* bt) {
    if (bt != NULL) {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout << bt->data << "  ";
    }
}
//求子树结点和
int Sum(BTNode* bt) {
    if (bt)
        return bt->data + Sum(bt->lchild) + Sum(bt->rchild);
    else
        return 0;
}
//求最大结点和子树并记录根结点位置及最大和
void MaxSubBT(BTNode* bt, int& index, int& ma) {
    if (bt) {
        int t = Sum(bt);
        if (t > ma) {
            ma = t;
            index = bt->data;
        }
        MaxSubBT(bt->lchild, index, ma);
        MaxSubBT(bt->rchild, index, ma);
    }
}

int main() {
    BTNode* bt;
    int a[1000], b[1000];
    char c;
    int i = 0;
    do {
        cin >> a[i++];
    } while ((c = getchar()) != '\n');
    i = 0;
    do {
        cin >> b[i++];
    } while ((c = getchar()) != '\n');
    int n = i;
    CreatePreInOrder(a, b, &bt, n);
    int ma = -1000, index;
    MaxSubBT(bt, index, ma);
    cout << "先序递归遍历：";
    PreOrder(bt);
    cout << endl;
    cout << "中序递归遍历：";
    InOrder(bt);
    cout << endl;
    cout << "后序递归遍历：";
    PostOrder(bt);
    cout << endl;
    cout << "以" << index << "为根的子树的所有结点和最大，最大和为：" << ma << "." << endl;
    return 0;
}