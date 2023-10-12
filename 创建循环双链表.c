#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
typedef struct node* LinkList;
struct node {
    int data;
    LinkList next, pre;             //˫��ѭ�����������ṹ��ָ��
};
LinkList CreateLink(int n){
    LinkList L;
    L = (LinkList)malloc(sizeof(struct node));
    L->next = L->pre = L;          //�Լ����Լ�����
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
}          //������ʼ��һ��ѭ������Ĳ���
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
    }//��������β��û���ҵ����Ԫ��
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
