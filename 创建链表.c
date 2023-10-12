#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int num;
	int score;
	struct ListNode* next;
};

int main() {
	char str[20];
	int i = 0;
	struct ListNode* head = NULL, * p;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = p;
	while (i < 3) {
		scanf("%s", str);
		sscanf(str, "%d,%d", &(p->num), &(p->score));
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		i++;
		p = p->next;
	}
	i = 0;
	while (head != NULL && i<3) {
		printf("[num=%d,score=%d]\n", head->num, head->score);
		head = head->next;
		i++;
	}
	return 0;
}