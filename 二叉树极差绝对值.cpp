#define _CRT_SECURE_NO_WARNINGS  1
#include <bits/stdc++.h>
using namespace std;

#define MaxSize 100        //定义最大长度
typedef int ElemType;  //定义数据类型    

//定义二叉树的链式存储结构
typedef struct tnode {
    ElemType data;                    //数据域
    struct tnode* lchild, * rchild;   //指针域
}BTNode;

//先序遍历
//引用变量记录最大最小值
void PreOrder(BTNode* bt,int &mi,int &ma) {
    if (bt) {
        mi = min(mi, bt->data);
        ma = max(ma, bt->data);
        cout << bt->data << "  ";
        PreOrder(bt->lchild, mi, ma);
        PreOrder(bt->rchild, mi, ma);
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

//由二叉树中后序遍历序列，求前序遍历序列。a,b为中后序遍历序列数组，n为结点数
//在之前的由二叉树中后序遍历序列，求先序遍历序列。
void CreateInPostOrder(int* a, int* b, BTNode** bt, int n) {
    int k;
    if (n <= 0)
        return;
    char root = b[n - 1];   //将当前b数组的尾字符作为根
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
    CreateInPostOrder(a, b, &bt, n);
    int mi = (int)1e9, ma = -1000;
    cout << "先序递归遍历：";
    PreOrder(bt, mi, ma);
    cout << endl;
    cout << "中序递归遍历：";
    InOrder(bt);
    cout << endl;
    cout << "后序递归遍历：";
    PostOrder(bt);
    cout << endl;
    cout << "该二叉树中最大值:" << ma << ",最小值为：" << mi << "." << endl;
    cout << endl;
    cout << "该二叉树中最大和最小值的差的绝对值为：" << ma - mi << "." << endl;
    return 0;
}
