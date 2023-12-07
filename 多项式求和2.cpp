#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode
{
	int coefficient;//ϵ��
	int exponent;//ָ��
	struct Lnode* next;
}LNODE;
//����һԪ����ʽA
/*LNODE* creatLA(int coef, int exp)
{
	LNODE* s = (LNODE*)malloc(sizeof(LNODE));
	//��ֵ
	s->coefficient = coef;
	s->exponent = exp;
	s->next = NULL;

	return s;
}
//����һԪ����ʽB
LNODE* creatLB(int coef, int exp)
{
	LNODE* p = (LNODE*)malloc(sizeof(LNODE));
	p->coefficient = coef;
	p->exponent = exp;
	p->next = NULL;

	return p;
}*/
//β�巨
void Insert(LNODE* Lhead)
{
	int coef, exp;
	LNODE* pre = Lhead;
	scanf("%d,%d", &coef, &exp);
	while (coef != 0 || exp != 0) {
		LNODE* p = (LNODE*)malloc(sizeof(LNODE));
		p->next = NULL;
		p->coefficient = coef;
		p->exponent = exp;
		pre->next = p;
		pre = p;
		scanf("%d,%d", &coef, &exp);
	}

}
//�������ʽ�ĺ�
LNODE* addL(LNODE* creatLAhead, LNODE* creatLBhead)
{
	LNODE* newL = (LNODE*)malloc(sizeof(LNODE));
	LNODE* p = newL;
	creatLAhead = creatLAhead->next;
	creatLBhead = creatLBhead->next;


	while (creatLAhead != NULL && creatLBhead != NULL)
	{
		LNODE* s = (LNODE*)malloc(sizeof(LNODE));
		if (creatLAhead->exponent == creatLBhead->exponent)
		{
			//ָ����ͬ��ϵ����� 
			s->coefficient = creatLAhead->coefficient + creatLBhead->coefficient;
			s->exponent = creatLAhead->exponent;
			creatLAhead = creatLAhead->next;
			creatLBhead = creatLBhead->next;
		}
		//ֱ�Ӽ�����
		else if (creatLAhead->exponent > creatLBhead->exponent)//�Ƚ�С�����ּ���
		{
			s->coefficient = creatLBhead->coefficient;
			s->exponent = creatLBhead->exponent;
			creatLBhead = creatLBhead->next;
		}
		else if (creatLAhead->exponent < creatLBhead->exponent)
		{
			s->coefficient = creatLAhead->coefficient;
			s->exponent = creatLAhead->exponent;
			creatLAhead = creatLAhead->next;
		}
		if (s->coefficient!=0) {
			p->next = s;
			p = p->next;
		}
			
		
	}
	p->next = NULL;
	if (creatLAhead != NULL)
	{
		p->next = creatLAhead;
		//p = creatLAhead;
		//p = p->next;
		//creatLAhead=creatLAhead->next;
	}
	else if (creatLBhead != NULL)
	{
		p->next = creatLBhead;
		//p = creatLBhead;
		//p = p->next;
		//creatLBhead=creatLBhead->next;
	}
	return newL;
}
void DispLNODE(LNODE* L) {
	LNODE* p = L->next;
	int i = 0;
	while (p != NULL)
	{
		if (i++==0)
			printf("%dx^%d", p->coefficient, p->exponent);
		else
			printf("+%dx^%d", p->coefficient, p->exponent);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	LNODE* creatLAhead = (LNODE*)malloc(sizeof(LNODE));
	LNODE* creatLBhead = (LNODE*)malloc(sizeof(LNODE));
	LNODE* newL = (LNODE*)malloc(sizeof(LNODE));
	Insert(creatLAhead);
	Insert(creatLBhead);
	LNODE* p = newL->next;

	newL = addL(creatLAhead, creatLBhead);
	DispLNODE(newL);
	return 0;
}

