#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
typedef struct node* LinkList;
struct node {
    int data;
    LinkList next, pre;             //双向循环链表两个结构体指针
};
LinkList CreateLink(int n){
    LinkList L;
    L = (LinkList)malloc(sizeof(struct node));
    L->next = L->pre = L;          //自己与自己相连
    LinkList p = L, q;
    while (n--) {
        q = (LinkList)malloc(sizeof(struct node));
        scanf("%d", &q->data);
        p->next = q;
        q->pre = p;
        q->next = L;
        L->pre = q;
        p = q;
    }
    return L;
}          //创建初始化一个循环链表的操作
LinkList merge(LinkList L){
    LinkList p = L->next;
    int m = p->data;
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
    LinkList r = L->next;
    while (r->data < m && r->next != L) {
        r = r->next;
    }
    if (r->next != L) {
        LinkList q;
        q = (LinkList)malloc(sizeof(struct node));
        q->data = m;
        q->pre = r->pre;
        q->next = r;
        r->pre->next = q;
        r->pre = q;
    }
    else {
        LinkList q;
        q = (LinkList)malloc(sizeof(struct node));
        q->data = m;
        r->next = q;
        q->pre = r;
        q->next = L;
        L->pre = q;
    }//遍历到了尾还没有找到大的元素
    return L;
}
void DispList(LinkList L){
    LinkList p = L->next;
    while (p != L){
        printf("%d ", p->data);
        p = p->next;
    }
}
int main(){
    int n;
    LinkList L, K;
    scanf("%d", &n);
    L = CreateLink(n);
    K = merge(L);
    DispList(K);
    return 0;
}
