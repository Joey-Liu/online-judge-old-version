/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL)
	{}
};

class Solution 
{
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) 
	{
		int len = 0;
		ListNode *pln = head;
		while (pln != NULL)
		{
			pln = pln->next;
			len++;
		}
		n = len - n + 1;

		ListNode* cur = new ListNode(-1), *prev = NULL;
		ListNode* H = cur;
		cur->next = head;
		int ind = 0;
		while (ind < n)
		{
			prev = cur;
			cur = cur->next;
			ind++;
		}
		prev->next = cur->next;
		return H->next;
	}
};