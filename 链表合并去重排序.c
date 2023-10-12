#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int val;
	struct ListNode* next;
};

struct ListNode* union_list(struct ListNode* head1, struct ListNode* head2) {
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	struct ListNode* head, * p;
	if (head1->val <= head2->val) {
		head = head1;
		head1 = head1->next;
	}
	else {
		head = head2;
		head2 = head2->next;
	}
	p = head;
	while (head1 != NULL && head2 != NULL) {
		if (head1->val <= head2->val) {
			p->next = head1;
			p = head1;
			head1 = head1->next;
		}
		else {
			p->next = head2;
			p = head2;
			head2 = head2->next;
		}
	}
	if (head1 == NULL) {
		p->next = head2;
	}
	else {
		p->next = head1;
	}
	return head;
}

int main() {
	int len1, len2, i;
	struct ListNode* head1 = NULL, * head2 = NULL, * p1, * p2;
	scanf("%d%d", &len1, &len2);
	if (len1 == 0) {
		head1 = NULL;
	}
	else {
		p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &(p1->val));
		head1 = p1;
		for (i = 1; i < len1; i++) {
			p1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			p1 = p1->next;
			scanf("%d", &(p1->val));
		}
		p1->next = NULL;
	}
	if (len2 == 0) {
		head2 = NULL;
	}
	else {
		p2 = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &(p2->val));
		head2 = p2;
		for (i = 1; i < len2; i++) {
			p2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
			p2 = p2->next;
			scanf("%d", &(p2->val));
		}
		p2->next = NULL;
	}
	struct ListNode* head = union_list(head1, head2);
	i = 0;
	int index;
	while (head != NULL) {
		if (i == 0) {
			index = head->val;
			printf("%d ", head->val);
		}
		else {
			if (head->val != index) {
				index = head->val;
				printf("%d ", head->val);
			}
		}
		i++;
		head = head->next;
	}
	printf("\n");
	return 0;
}