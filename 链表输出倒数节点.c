#define _CRT_SECURE_NO_WARNINGS  1
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
	int val;
	struct ListNode* next;
};

int main() {
	int arr[100], index = 0;
	int i = 0, k;
	scanf("%d", &k);
	while (1) {
		scanf("%d", &index);
		if (index == -1)
			break;
		arr[i++] = index;
	}
	int len = i;
	struct ListNode* head = NULL, * p;
	p = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = p;
	i = 0;
	while (i < len) {
		p->val = arr[i];
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		i++;
		p = p->next;
	}
	p = NULL;
	if (k > len) 
		printf("Not Found\n");
	else {
		i = 0;
		while (i<len-k) {
			head = head->next;
			i++;
		}
		printf("%d", head->val);
	}
	return 0;
}