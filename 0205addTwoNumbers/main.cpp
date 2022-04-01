#include <stdio.h>
#include "addTwoNumbers.h"

void printListInAddTwoNumbers(ListNode* head)
{
	while (NULL != head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n\n");

	return;
}

void addNodeInAddTwoNumbers(ListNode* head, int n)
{
	ListNode* node = new ListNode(n);
	node->next = head->next;
	head->next = node;
}

void initList1(ListNode* head)
{
	addNodeInAddTwoNumbers(head, 6);
	addNodeInAddTwoNumbers(head, 1);
	addNodeInAddTwoNumbers(head, 7);
}

void initList2(ListNode* head)
{
	addNodeInAddTwoNumbers(head, 2);
	addNodeInAddTwoNumbers(head, 9);
	addNodeInAddTwoNumbers(head, 5);
}

int main()
{
	ListNode* l1 = new ListNode(0);
	initList1(l1);

	ListNode* l2 = new ListNode(0);
	initList2(l2);

	printListInAddTwoNumbers(l1->next);
	printListInAddTwoNumbers(l2->next);

	SolutionAddTwoNumbers s;
	ListNode* ret = s.addTwoNumbers(l1->next, l2->next);

	printListInAddTwoNumbers(ret);

	return 0;
}