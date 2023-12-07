#define _CRT_SECURE_NO_WARNINGS 1
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

//先序递归创建
void BinTreeCreate(BTNode*& bt) {
    int num;
    char ch;
    cin >> num;
    if (num == 0) {
        bt = NULL;
        ch = getchar();
        if (ch == '\n') 
            return;  
    }
    else {
        bt = (BTNode*)malloc(sizeof(BTNode));
        bt->data = num;
        ch = getchar();
        if (ch == '\n')
            return;
        BinTreeCreate(bt->lchild);
        BinTreeCreate(bt->rchild);
    }
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
//递归计算非叶子结点值
void LeafVal(BTNode*& bt) {
    if (bt) {
        if (bt->lchild && bt->rchild) {
            LeafVal(bt->lchild);
            LeafVal(bt->rchild);
            bt->data = bt->lchild->data + bt->rchild->data;   //当前结点的左右孩子都存在时，尾递归当前结点为左右孩子结点值之和
        }
        else if (bt->lchild && !bt->rchild) {   //单分支时（右）
            LeafVal(bt->lchild);
            bt->data = bt->lchild->data;
        }
        else if (!bt->lchild && bt->rchild) {   //单分支时（左）
            LeafVal(bt->rchild);
            bt->data = bt->rchild->data;
        }
    }
}

int main() {
    BTNode* bt;
    BinTreeCreate(bt);
    LeafVal(bt);
    
    cout << endl;
    cout << "先序递归创建二叉树，输入数据如（-1表示无值）：-1 -1 0 1 0 0 -1 2 0 0 0:" << endl;
    cout << "所有非叶子结点求值的二叉树的先序遍历：";
    PreOrder(bt);
    cout << endl;
    cout << "所有非叶子结点求值的二叉树的中序遍历：";
    InOrder(bt);
    cout << endl;
    cout << "所有非叶子结点求值的二叉树的后序遍历：";
    PostOrder(bt);
    cout << endl;
    return 0;
}