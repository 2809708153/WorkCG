#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>

typedef struct Lnode
{
	int coefficient;//系数
	int exponent;//指数
	struct Lnode* next;
}LNODE;
//创建一元多项式A
/*LNODE* creatLA(int coef, int exp)
{
	LNODE* s = (LNODE*)malloc(sizeof(LNODE));
	//赋值
	s->coefficient = coef;
	s->exponent = exp;
	s->next = NULL;

	return s;
}
//创建一元多项式B
LNODE* creatLB(int coef, int exp)
{
	LNODE* p = (LNODE*)malloc(sizeof(LNODE));
	p->coefficient = coef;
	p->exponent = exp;
	p->next = NULL;

	return p;
}*/
//尾插法
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
//计算多项式的和
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
			//指数相同，系数相加 
			s->coefficient = creatLAhead->coefficient + creatLBhead->coefficient;
			s->exponent = creatLAhead->exponent;
			creatLAhead = creatLAhead->next;
			creatLBhead = creatLBhead->next;
		}
		//直接加入结点
		else if (creatLAhead->exponent > creatLBhead->exponent)//先将小的数字加入
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

