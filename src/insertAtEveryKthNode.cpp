/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node *insertNode(struct node *head, int element){
	struct node *new1 = (struct node *)malloc(sizeof(struct node));
	new1->num = element;
	new1->next = head;
	return new1;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head==NULL||K<1)
		return NULL;
	int count;
	struct node *temp;
	temp = head;
	count = K;
	while (temp != NULL){
		if (count == 1){
			temp->next=insertNode(temp->next, K);
			count = K;
			temp = temp->next->next;
		}
		else{
			temp = temp->next;
			count -= 1;
		}
	}
	return head;
}
