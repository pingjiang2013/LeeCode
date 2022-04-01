#pragma once

#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addNodeToTail(ListNode* tail, int n)
{
	ListNode* node = new ListNode(n);
	node->next = NULL;
	tail->next = node;

	return node;
}

class SolutionAddTwoNumbers {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};