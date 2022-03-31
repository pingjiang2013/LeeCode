#include <stdio.h>
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

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
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
};

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
void initList(ListNode* head)
{
	addNode(head, 2);
	addNode(head, 5);
	addNode(head, 2);
	addNode(head, 3);
	addNode(head, 4);
	addNode(head, 1);
}

int main()
{
	ListNode* head = new ListNode(0);
	initList(head);

	printList(head->next);

	Solution s;
	ListNode* ret = s.partition(head->next, 3);

	printList(ret);

	return 0;
}