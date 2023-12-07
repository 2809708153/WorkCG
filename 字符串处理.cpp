#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[1000], s2[1000], ch;
	int i = 0;
	while ((ch = getchar()) != '#') {
		s[i++] = ch;
	}
	int j = i - 1, len = i;
	i = 0;
	int k;
	//奇数填到新数组前面，偶数填后面
	for (k = 0; k < len; k++) {
		if (!(k & 1)) {
			s2[i++] = s[k];
		}
		else {
			s2[j--] = s[k];
		}
	}
	s2[len] = '\0';
	printf("%s", s2);
	system("pause");
	return 0;
}






//
////法二，奇数尾插偶数头插，最后链表顺序改变
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct List {
//	char data;
//	struct List *next;
//}list;
//
//void init(list **L) {
//	(*L) = (list*)malloc(sizeof(list));
//	(*L)->next = NULL;
//}
//void CreatF(list **L, char *arr, int n) {
//	list*tc, *s;
//	tc = *L;
//	int i = 0;
//	while (i < n) {
//		s = (list*)malloc(sizeof(list));
//		s->data = arr[i++];
//		tc->next = s;
//		s->next = NULL;
//		tc = s;
//	}
//}
//
////奇数字符尾插，偶数字符头插
//void fff(list **L, char *str,int n) {
//	int i = 0;
//	list*p = (*L);
//	list*tc = (*L),*s;
//	while (i < n) {
//		if (!(i&1)) {
//			s = (list*)malloc(sizeof(list));
//			s->data = str[i];
//			tc->next = s;
//			tc = s;
//		}
//		else {
//			s = (list*)malloc(sizeof(list));
//			s->data = str[i];
//			s->next = (*L)->next;
//			(*L)->next = s;
//		}
//		i++;
//	}
//	tc->next = NULL;
//}
//void Disp(list *L) {
//	list*p = L->next;
//	while (p) {
//		printf("%c", p->data);
//		p = p->next;
//	}
//	printf("\n");
//}
//int main() {
//	char a[1000];
//	list*r;
//	init(&r);
//	char ch;
//	int i = 0;
//	while ((ch = getchar()) != '#') {
//		a[i++] = ch;
//	}
//	fff(&r, a, i);
//	Disp(r);
//	system("pause");
//	return 0;
//}

