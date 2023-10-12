#include <iostream>
#include <bits/stdc++.h>
using namespace std;


typedef int Status;
typedef int ElemType;    //Ԫ������ 
#define LIST_INIT_SIZE 100 
#define LISTINCREMENT 10 
typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;    //������� 
//2�� ��غ���������α�����£�
Status InitList(SqList * L) {
	L->elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L->elem) exit(OVERFLOW);    //�洢����ʧ�� 
	L->length = 0; 	//�ձ���Ϊ�� 
	L->listsize = LIST_INIT_SIZE;      //��ʼ�洢���� 
	return OK;
}
Status DestroyList(SqList* L) {
	if (L->elem)
		free(L->elem); 	//�ͷ����Ա�ռ�õĴ洢�ռ� 
	L->elem = NULL; 	//�ÿ� 
	L->length = 0;
	L->listsize = 0;
	return OK;
}
Status ClearList(SqList* L) {
	L->length = 0;
	return OK;
}
Status ListEmpty(SqList L) {
	if (L.length == 0) return TRUE; //������Ϊ�㣬����TRUE 
	else return FALSE;


}
int ListLength(SqList L) {
	return L.length;
}
Status GetElem(SqList L, int i, ElemType* e) {
	if (i<1 || i>L.length) return FALSE; 	//��������Χ������FALSE 
	*e = L.elem[i - 1]; 	//��e���ص�i������ 
	return OK;
}
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType) {
	i = 1;
	p = L.elem;  //p�ĳ�ֵΪ�洢�ռ��ַ 
	while (i <= L.length && !(*compare)(*p++, e)) ++i;
	if (i < L.length) return i;  //��������������Ԫ�أ�������Ӧλ�� 
	else return 0;
}
Status PriorElem(SqList L, ElemType cur_e, ElemType* pre_e) {
	for (i = 2; i <= L.length; i++) {
		if (L.elem[i - 1] == cur_e) {
			*pre_e = L.elem[i - 2];
			return OK;
		}
		else continue;
	}//�ӵڶ���Ԫ�ؿ�ʼ�ң�������cur_e��ȵ�����Ԫ�أ�����ǰ����ֵ����pre_e������   return FALSE; 
}
Status NextElem(SqList L, ElemType cur_e, ElemType* next_e) {
	for (i = 1; i < L.length; i++) {
		if (L.elem[i - 1] == cur_e) {
			*pre_e = L.elem[i];
			return OK;
		}//�ӵ�һ��Ԫ�ؿ�ʼ�ң�һֱ�������ڶ���Ԫ�أ�������cur_e��ȵ�����Ԫ�أ������̵�ֵ����pre_e������ 
		else continue;
	}
	return FALSE;
}
Status ListInsert(SqList* L, int i, ElemType e) {


	if (i<1 || i>(*L).length + 1) return ERROR;  //iֵ���Ϸ������ 
	if ((*L).length > (*L).listsize) {
		ElemType* newbase = (ElemType*)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType)); //���ӷ��� 
		if (!newbase) exit(OVERFLOW); 	//����ʧ�� 
		L->elem = newbase; 	//�µĻ�ַ 
		L->listsize += LISTINCREMENT;
	}
	q = &(L->elem[i - 1]); 	//qΪ�����λ�� 
	for (p = &(L->elem[L->length - 1]); p >= q; --p) *(p + 1) = *p; //����λ��֮���Ԫ��һһ���� 
	*q = e; 	//����e 
	L->length++; 	//����һ 
	return OK;
}
Status ListDelete(SqList* L, int i, ElemType* e) {
	if ((i < 1) || (i > L->length)) return ERROR; 	//iֵ���Ϸ� 
	p = &(L->elem[i - 1]); 	//pΪ��ɾԪ��λ�� 
	*e = *p; 	//����ɾԪ�ص�ֵ����e 
	q = L->elem + L->length - 1; 	//ĩβԪ��λ�� 
	for (++p; p <= q; ++p) *(p - 1) = *(p); 	//��ɾԪ��֮���Ԫ������ 
	L->length--; 	//����һ 
	return OK;
}
Status ListTraverse(SqList L, void(*visit)(ElemType*)) {
	for (i = 1; i <= L.length; i++)

		visit(&L.elem[i - 1]);
	return OK;
}


//���ζ�ÿ������Ԫ�ص��ú���visit() 

3�� ��������α���㷨��
int main() {
	printf("��������������ݽ��в���\n");
	printf("�����µ�˳���L\n");
	if (InitList(&L)) printf("�����ɹ�\n");
	else printf("����ʧ��\n");
	printf("\n");
	printf("����Ԫ�ظ���n\n");
	scanf("%d", &n);
	printf("\n");
	printf("����%d������Ԫ��\n", n);
	for (i = 1; i <= n; i++) {
		scanf(temp);


		ListInsert(&L, i, temp);
	}
	printf("\n");
	printf("�����������(������Ӧ���)��ɸ�������\n");
	printf("1:�����Ա�����Ϊ�ձ�\n");
	printf("2:�ж����Ա��Ƿ�Ϊ��\n");
	printf("3:�����Ա�ĳ���\n");
	printf("4:�����Ա��е�i��Ԫ�ص�ֵ\n");
	printf("5:�����Ա���ֵΪe�ĺ�����λ��\n");
	printf("6:��Ԫ��cur_e��ǰ��Ԫ�ص�ֵ\n");
	printf("7:��Ԫ��cur_e�ĺ��Ԫ�ص�ֵ\n");
	printf("8:��L�ĵ�i��λ��֮ǰ�����µ�����Ԫ��e\n");
	printf("9:ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ\n");
	printf("10:�������Ա������Ԫ�ص�ֵ\n");
	printf("0:��������\n\n");
	do {
		scanf("%d", &num);
		switch (num) {
		case 1:ClearList(&L); break;
		case 2:
			if (ListEmpty(L)) printf("�����Ա�Ϊ��\n");
			else printf("�����Ա�ǿ�\n");
			break;
		case 3:
			printf("���Ա�ĳ���Ϊ%d\n", ListLength(L));
			break;
		case 4:
			printf("����λ��i\n");
			scanf("%d", &i);
			if (GetElem(L, i, &e) == 0) printf("iֵ���Ϸ�\n");
			else printf("��%dλ�ϵ�����Ԫ��Ϊ%d\n", i, e); break;
		case 5:
			printf("����e��ֵ\n");
			scanf("%d", &e);
			if (LocateElem(L, e, compare)) printf("ֵΪ%d��Ԫ���ڵ�%dλ\n", e, LocateElem(L, e, compare));
			else printf("ֵΪ%d�����ݲ�����\n", e); break;
		case 6:
			printf("����cur_e��ֵ\n");
			scanf(cur_e);
			if (PriorElem(L, cur_e, &pre_e)) printf("%d��ǰ��Ԫ��Ϊ%d\n", cur_e, pre_e); else printf("������%d��ǰ��Ԫ��\n", cur_e); break;
		case 7:


			printf("����cur_e��ֵ\n");
			scanf(cur_e);
			if (NextElem(L, cur_e, &next_e)) printf("%d�ĺ��Ԫ��Ϊ%d\n", cur_e, next_e); else printf("������%d�ĺ��Ԫ��\n", cur_e); break;
		case 8:
			printf("�ֱ��������Ԫ��e�����λ��i��ֵ\n");
			scanf(e, i);
			if (ListInsert(&L, i, e)) printf("����ɹ�\n");
			else printf("����ʧ��\n");
			break;
		case 9:
			printf("����ɾ��λ��i��ֵ\n");
			scanf(i);
			if (ListDelete(&L, i, &e)) printf("��ɾ����%dλ��Ԫ��%d\n", i, e);
			else printf("iֵ���Ϸ�\n"); break;
		case 10:
			printf("��ǰ���Ա�Ϊ:\n");
			ListTraverse(L, visit); break;
		case 0:
			DestroyList(&L);
			break;
		}
		printf("\n");
	} while (num != 0);
	return 0;
}
������  ��ͷ���ĵ�����ı�ʾ��ʵ��
1�� Ԫ�����ͣ�������ͺ�ָ�����ͣ�
typedef int Status;
typedef int ElemType;
typedef struct LNode {
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;
2�� ��غ�����α���㷨��
void CreatList_L(LinkList * L, int n) {
	*L = (LinkList)malloc(sizeof(LNode));

	(*L)->next = NULL;
	q = L;
	for (i = n; i > 0; i--) {


		//�Ƚ���һ����ͷ���ĵ����� 

		p = (LinkList)malloc(sizeof(LNode)); //�����½�� 
		scanf("%d", &(p->data)); 	//����Ԫ��ֵ 
		p->next = (*L)->next;


		q->next = p; 	//���뵽��β 
		q = p;
	}
	p->next = NULL;
	return OK;
}//˳λ������n��Ԫ�ص�ֵ��������ͷ���ĵ������Ա� 
Status InitList(LinkList* L) {
	*L = (LinkList)malloc(sizeof(LNode)); 	//����ͷ��� 
	if (!*L) exit(OVERFLOW); 	//����ʧ�� 
	(*L)->next = NULL;
	return OK;
}
Status DestroyList(LinkList L) {
	p = L;  //p�ĳ�ʼλ��Ϊͷ���λ�� 
	while (p) {
		q = p->next;
		free(p); 	//�ͷŽ�� 
		p = q;
	}
	return OK;
}
Status ClearList(LinkList L) {
	p = L->next;
	while (p) {
		q = p->next;
		free(p); 	//�ͷŽ�� 
		p = q;
	}
	L->next = NULL; 	//��Ϊ�ձ� 
	return OK;
}
Status ListEmpty(LinkList L) {

	if (L->next) return FALSE;
	else return TRUE;
}
int ListLength(LinkList L) {


	//������Ϊ�գ�����FALSE 
	//������Ϊ�գ�����TRUE 

	i = 0; p = L->next; 	//��i��¼���ȣ���i�ĳ�ֵΪ�� 
	while (p) {
		i++;


		p = p->next;
	}
	return i;
}
Status GetElem_L(LinkList L, int i, ElemType* e) {
	p = L->next; j = 1; 	//pָ���һ�����,j���м��� 
	while (p && j < i) { 	//˳��ָ�������ң�ֱ��ָ���i��Ԫ�ػ�pΪ�� 
		p = p->next;
		j++;
	}
	if (!p || j > i) return ERROR; 	//��i��Ԫ�ز����� 
	*e = p->data; 	//ȡ��i��Ԫ�� 
	return OK;
}
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
	p = L->next; i = 1; 	//i��ʾ��ǰԪ��λ�� 
	while (p) {
		if (compare(e, p->data)) return i; 	//������compare���������ض�Ӧλ��i 
		else { 	//����ָ����һ����� 
			p = p->next;
			i++;
		}
	}
	return 0;
}
Status PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e) {
	q = L->next; 	//��q���洢ǰһ����� 
	p = q->next;
	while (p) {
		if (p->data == cur_e) {
			*pre_e = q->data;
			return OK;
		}
		P->next; q = q->next;
	}//�ӵڶ���Ԫ�ؿ�ʼ�ң�������cur_e��ȵ�����Ԫ�أ�����ǰ����ֵ����pre_e������   return FALSE; 
}
Status NextElem(LinkList L, ElemType cur_e, ElemType* next_e) {
	q = L->next;
	p = q->next; 	//p��ʾ���Ԫ�ؽ��λ�� 


	while (p) {
		if (q->data == cur_e) {
			*pre_e = p->data;
			return OK;
		}
		P = p->next; q = q->next;
	}
	return FALSE;
}
Status ListInsert_L(LinkList* L, int i, ElemType e) {
	p = L;
	j = 0;
	while (p && j < i - 1) {
		p = p->next; ++j;
	}
	if (!p || j > i - 1) return ERROR;
	LinkList s = (LinkList)malloc(sizeof(LNode)); 	//�����½�� 
	s->data = e; s->next = p->next;
	p->next = s;
	return OK;
}
Status ListDelete(LinkList* L, int i, ElemType* e) {
	p = L;
	j = 0;
	while (p->next && j < i - 1) { 	//Ѱ�ҵ�i����㣬pΪ��ǰ�� 
		p = p->next; ++j;
	}

	if (!(p->next) || j > i - 1) return ERROR;
	q = p->next;
	p->next = q->next;
	*e = q->data;


	//ɾ����λ�ò��������� 

	free(q); 	//ɾ���ͷŽ�� 
	return OK;
}
Status ListTraverse(LinkList L, void(*visit)(ElemType*)) {
	p = L->next;
	while (p) {

		visit(&p->data);
		p = p->next;
	}
	return OK;


	//�Ը���������ִ��visit���� 


}