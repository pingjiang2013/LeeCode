#include <stdio.h>
#include "addTwoNumbers.h"

ListNode* SolutionAddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2) {
	int carry = 0;
	int sum = 0;
	ListNode* head = new ListNode(0);
	ListNode* tail = head;

	while (NULL != l1 && NULL != l2)
	{
		sum = l1->val + l2->val + carry;
		carry = sum > 9 ? 1 : 0;

		sum = sum - carry * 10;
		tail = addNodeToTail(tail, sum);
		l1 = l1->next;
		l2 = l2->next;
	}

	// 如果l1和l2长度不同，没有同时到结尾
	if (l1 != l2)
	{
		ListNode* left = NULL == l1 ? l2 : l1;

		while (NULL != left)
		{
			sum = left->val + carry;
			carry = sum > 9 ? 1 : 0;

			sum = sum - carry * 10;
			tail = addNodeToTail(tail, sum);
			left = left->next;
		}
	}

	if (0 != carry)
	{
		addNodeToTail(tail, carry);
	}
	return head->next;
}


void printList(ListNode* head)
{
	while (NULL != head)
	{
		printf("%d ", head->val);
		head = head->next;
	}
	printf("\n\n");

	return;
}

void addNode(ListNode* head, int n)
{
	ListNode* node = new ListNode(n);
	node->next = head->next;
	head->next = node;
}

void initList1(ListNode* head)
{
	addNode(head, 6);
	addNode(head, 1);
	addNode(head, 7);
}

void initList2(ListNode* head)
{
	addNode(head, 2);
	addNode(head, 9);
	addNode(head, 5);
}

int main()
{
	ListNode* l1 = new ListNode(0);
	initList1(l1);

	ListNode* l2 = new ListNode(0);
	initList2(l2);

	printList(l1->next);
	printList(l2->next);

	SolutionAddTwoNumbers s;
	ListNode* ret = s.addTwoNumbers(l1->next, l2->next);

	printList(ret);

	return 0;
}