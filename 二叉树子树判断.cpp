#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MaxSize 100        //定义最大长度
typedef char ElemType;  //定义数据类型    

//定义二叉树的链式存储结构
typedef struct tnode {
    ElemType data;                    //数据域
    struct tnode* lchild, * rchild;   //指针域
}BTNode;

//先序递归创建
void BinTreeCreate(BTNode*& bt) {
	ElemType ch;
	cin >> ch;
	if (ch == '\n')  //递归出口
		return;
	if (ch == '#')
		bt = NULL;
	else {
		bt = (BTNode*)malloc(sizeof(BTNode));
		bt->data = ch;
		BinTreeCreate(bt->lchild);
		BinTreeCreate(bt->rchild);
	}
}
//先序遍历
void PreOrder(BTNode* bt) {
	if (bt) {
		cout << bt->data;
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}
//判断是否为子树
//判断是否有相同的子树结构
int IsSubTree(BTNode* root, BTNode* subRoot){
	if (subRoot == NULL)
		return 1;
	if (root == NULL)
		return 0;
	if (root->data != subRoot->data)
		return 0;
	return IsSubTree(root->lchild, subRoot->lchild)
		& IsSubTree(root->rchild, subRoot->rchild);
}
//找相同的根结点
int FindSameRoot(BTNode* root, BTNode* subRoot){
	int res = 0;
	if (root != NULL && subRoot != NULL){
		if (root->data == subRoot->data)
			res = IsSubTree(root, subRoot);
		if (!res)
			res = FindSameRoot(root->lchild, subRoot);
		if (!res)
			res = FindSameRoot(root->rchild, subRoot);
	}
	return res;
}

int main() {
	BTNode* bt1,* bt2;
	BinTreeCreate(bt1);
	BinTreeCreate(bt2);
	cout << "先序递归创建二叉树rt1，输入数据如:AB##CD###:" << endl;
	cout << "先序递归创建二叉树rt2，输入数据如:AB##CD###:" << endl;
	
	//PreOrder(bt1);   //调试部分
	//cout << endl;
	//PreOrder(bt2);
	//cout<<endl;
	if (FindSameRoot(bt1, bt2))
		cout << "二叉树r2是二叉树r1的子树!";
	else
		cout << "二叉树r2不是二叉树r1的子树!";
	return 0;
}
