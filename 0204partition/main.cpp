#include <stdio.h>
#include "partition.h"

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