#define _CRT_SECURE_NO_WARNINGS  1
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//�������ʽ����
typedef struct node {
	float coef;
	int exp;
	struct node* next;


}PolyNode;
//β�巨�����崴������
void CreateListR(PolyNode*& L, float* a,int *b, int n) {
	PolyNode* s, * tc;
	int i;
	L = (PolyNode*)malloc(sizeof(PolyNode));
	tc = L;
	for (i = 0; i < n; i++) {
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->coef = a[i];
		s->exp = b[i];
		tc->next = s;
		tc = s;
	}
	tc->next = NULL;
}
//��������
void DestroyList(PolyNode*& L) {
	PolyNode* pre = L, * p = pre->next;
	while (p != NULL) {
		free(pre);
		pre = p; p = p->next;
	}
	free(pre);
}
//�������
void DispPoly(PolyNode* L) {
	PolyNode* p = L->next;
	while (p != NULL) {
		cout << p->coef << "x^" << p->exp;
		if (p->next != NULL)
			cout << "+";
		p = p->next;
	}
	cout << endl;
}
//��ʽ��Ӻ���
void Add(PolyNode* ha, PolyNode* hb, PolyNode*& hc) {
	PolyNode* pa = ha->next, * pb = hb->next, * s, * tc;
	float c;
	hc = (PolyNode*)malloc(sizeof(PolyNode));
	tc = hc;
	while (pa != NULL && pb != NULL) {
		if (pa->exp < pb->exp){     //������С����ΪС�ڣ���֮
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->exp = pa->exp; 
			s->coef = pa->coef;
			tc->next = s; 
			tc = s;
			pa = pa->next;
		}
		else if (pa->exp > pb->exp) {
			s = (PolyNode*)malloc(sizeof(PolyNode));
			s->exp = pb->exp; 
			s->coef = pb->coef;
			tc->next = s; 
			tc = s;
			pb = pb->next;
		}
		else {
			c = pa->coef + pb->coef;
			if (c != 0) {
				s = (PolyNode*)malloc(sizeof(PolyNode));
				s->exp = pa->exp; 
				s->coef = c;
				tc->next = s;
				tc = s;
			}
			pa = pa->next;
			pb = pb->next;
		}
	}
	if (pb != NULL) 
		pa = pb;
	while (pa != NULL) {
		s = (PolyNode*)malloc(sizeof(PolyNode));
		s->exp = pa->exp;
		s->coef = pa->coef;
		tc->next = s; 
		tc = s;
		pa = pa->next;
	}
	tc->next = NULL;
}

int main() {
	PolyNode* Poly1, * Poly2, * Poly3;
	float coef[100], c;
	int exp[100], e;
	int i = 0;
	while (1) {
		scanf("%f,%d", &c, &e);
		if (c == 0 && e == 0)
			break;
		coef[i] = c;
		exp[i++] = e;
	}
	CreateListR(Poly1, coef, exp, i);
	i = 0;
	while (1) {
		scanf("%f,%d", &c, &e);
		if (c == 0 && e == 0)
			break;
		coef[i] = c;
		exp[i++] = e;
	}
	CreateListR(Poly2, coef, exp, i);
	Add(Poly1, Poly2, Poly3);
	DispPoly(Poly3);
	DestroyList(Poly1);
	DestroyList(Poly2);
	DestroyList(Poly3);
	return 0; 
}
