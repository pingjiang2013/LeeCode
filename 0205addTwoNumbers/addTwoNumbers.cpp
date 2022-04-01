#include <stdio.h>
#include "addTwoNumbers.h"


ListNode* addNodeToTail(ListNode* tail, int n)
{
	ListNode* node = new ListNode(n);
	node->next = NULL;
	tail->next = node;

	return node;
}

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

	// ���l1��l2���Ȳ�ͬ��û��ͬʱ����β
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

