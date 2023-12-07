#define _CRT_SECURE_NO_WARNINGS  1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxSize 100        //������󳤶�
typedef int ElemType;  //������������    

//�������������ʽ�洢�ṹ
typedef struct tnode {
    ElemType data;                    //������
    struct tnode* lchild, * rchild;   //ָ����
}BTNode;

//���ű��ʽ����������
void CreateBTree(BTNode** bt, char* str) {
    BTNode* St[MaxSize], * p = NULL;  
    int top = -1, k = 0, j = 0, len = (int)strlen(str);
    char ch;
    (*bt) = NULL;
    ch = str[j];
    while (ch != '\0') {
        switch (ch) {
        case '(':
            top++;
            St[top] = p;
            k = 1;
            break;
        case ')':
            top--;
            break;
        case ',':
            k = 2;
            break;
        default:
            p = (BTNode*)malloc(sizeof(BTNode));
            int num = (int)ch - 48;
            while (j + 1 < len && str[j + 1] <= '9' && str[j + 1] >= '0') {    //�����λ��
                num = num * 10 + (int)str[j + 1] - 48;
                j++;   //��һ���ַ�
            }   
            p->data = num;
            p->lchild = p->rchild = NULL;
            if ((*bt) == NULL)
                (*bt) = p;
            else {
                switch (k) {
                case 1:
                    St[top]->lchild = p;
                    break;
                case 2:
                    St[top]->rchild = p;
                    break;
                }
            }
        }
        j++;
        ch = str[j];
    }
}

typedef BTNode* type;
typedef struct {
    type data[MaxSize];
    int front, rear;
}Queue;
//���г�ʼ��
Queue* InitQueue() {
    Queue* sq = (Queue*)malloc(sizeof(Queue));
    sq->rear = sq->front = 0;
    return sq;
}
void Push(Queue* sq, BTNode* x) {
    if ((sq->rear + 1) % MaxSize == sq->front) {
        return;
    }
    sq->rear = (sq->rear + 1) % MaxSize;
    sq->data[sq->rear] = x;
    return;
}
int CD(Queue sq) {
    return (sq.rear - sq.front);
}
BTNode* PopTop(Queue* sq) {
    if (sq->rear == sq->front) {
        return 0;
    }
    else {
        sq->front = (sq->front + 1) % MaxSize;
        return sq->data[sq->front];
    }
}
int Empty(Queue sq) {
    if (sq.front == sq.rear)return 1;
    else return 0;
}
void DisTreec(BTNode* t, int(*b)[100], int* floor) {
    if (t == NULL) 
        return;
    Queue* q = InitQueue();
    Push(q, t);
    //int floor = 0;
    while (!Empty(*q)) {
        int level = CD(*q), count = 0;
        while (level--) {
            BTNode* node = PopTop(q);
            b[*floor][count] = node->data;
            count++;
            if (node->lchild != NULL) {
                Push(q, node->lchild);
            }
            if (node->rchild != NULL) {
                Push(q, node->rchild);
            }
        }
        b[*floor][count] = 0;
        (*floor)++;
    }
}

//void LevelOrder(BTNode* bt) {
//    BTNode* stack[MaxSize], * node;
//    node = bt;
//    int front = 0; //���ж�ͷ
//    int rear = 0;  //���ж�β
//    stack[rear++] = node;
//    if (bt == NULL) {
//        printf("��Ϊ������\n");
//        return;
//    }
//    while (front != rear) {   //���в�Ϊ��
//        node = stack[front++];//�Ȼ�ȡ��ͷԪ�أ�Ȼ����ָ����е���һλԪ��
//        printf("%d ", node->data);  //����
//        if (node->lchild)
//            stack[rear++] = node->lchild; 
//        if (node->rchild)
//            stack[rear++] = node->rchild; 
//    }
//}


int main() {
    BTNode* bt;
    char s[1000];
    int arr[100][100];
    scanf("%s", s);
    CreateBTree(&bt, s);
    int floor = 0, i;
    DisTreec(bt, arr, &floor);
    for (i = floor - 1; i > -1; i--) {
        int j = 0;
        while (arr[i][j] != 0) {
            printf("%d ", arr[i][j]);
            j++;
        }
        printf("\n");
    }
    return 0;
}