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

