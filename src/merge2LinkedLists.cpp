/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	else if (head1 == NULL)
		return head2;
	else if (head2==NULL)
		return head1;
	int count = 0, i;
	struct node *node1, *node2, *result, *current;
	node1 = head1;
	node2 = head2;
	if (head1->num < head2->num){
		result = head1;
		node1 = head1->next;
		current = result;
	}
	else{
		result = head2;
		node2 = head2->next;
		current = result;
	}
	while (node1 != NULL&&node2 != NULL){
		if (node1->num < node2->num){
			current->next = node1;
			node1 = node1->next;
			current = current->next;
		}
		else{
			current->next = node2;
			node2 = node2->next;
			current = current->next;
		}
	}
	if (node1 != NULL)
		current->next = node1;
	else if (node2 != NULL)
		current->next = node2;
	return result;
}
