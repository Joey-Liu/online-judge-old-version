#include <iostream>

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) 
	{
		ListNode *ln = new ListNode(-1);
		ListNode *re = ln;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				ln->next = l1;
				l1 = l1->next;
			}
			else
			{
				ln->next = l2;
				l2 = l2->next;
			}
			ln = ln->next;
		}
		l1 == NULL ? ln->next = l2 : ln->next = l1;
		return re->next;
	}
};