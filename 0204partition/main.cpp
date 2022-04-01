#include <stdio.h>
#include "partition.h"

ListNode* SolutionPartition::partition(ListNode* head, int x) {
	ListNode* first = new ListNode(0);
	ListNode* previous = first;
	first->next = head;

	ListNode* current = head;

	while (NULL != current && current->val < x)
	{
		previous = current;
		current = current->next;
	}
	if (NULL == current) return head;

	while (NULL != current)
	{
		if (current->val < x)
		{
			previous->next = current->next;
			current->next = first->next;
			first->next = current;
			current = previous->next;
		}
		else
		{
			previous = current;
			current = current->next;
		}
	}
	ListNode* ret = first->next;
	delete first;

	return ret;
}


void printListInPartition(ListNode* head)
{
	while (NULL != head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n\n");

	return;
}

void addNodeInPartition(ListNode* head, int n)
{
	ListNode* node = new ListNode(n);
	node->next = head->next;
	head->next = node;
}
void initListInPartition(ListNode* head)
{
	addNodeInPartition(head, 2);
	addNodeInPartition(head, 5);
	addNodeInPartition(head, 2);
	addNodeInPartition(head, 3);
	addNodeInPartition(head, 4);
	addNodeInPartition(head, 1);
}

int main()
{
	ListNode* head = new ListNode(0);
	initListInPartition(head);

	printListInPartition(head->next);

	SolutionPartition s;
	ListNode* ret = s.partition(head->next, 3);

	printListInPartition(ret);

	return 0;
}