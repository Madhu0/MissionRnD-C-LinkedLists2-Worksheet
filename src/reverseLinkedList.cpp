/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverse(struct node *head, struct node *current){
	struct node *temp;
	temp = head->next;
	head->next = current;
	current = head;
	head = temp;
	if (head != NULL)
		return reverse(head, current);
	else
		return current;
}

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	struct node *rev;
	rev = NULL;
	rev = reverse(head, rev);
	return rev;
}
