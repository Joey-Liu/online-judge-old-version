#include <iostream>
#include <stdio.h>

using namespace std;


struct ListNode 
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) \
	{
		ListNode *resNode = new ListNode(0);
		ListNode *preNode = resNode;

		while (l1 != NULL || l2 != NULL)
		{
			int a = (l1 != NULL) ? l1->val : 0;
			int b = (l2 != NULL) ? l2->val : 0;
			ListNode *te = new ListNode(a + b);
			preNode->next = te;
			preNode = te;
			if (l1 != NULL && l1->next)
				l1 = l1->next;
			else
				l1 = NULL;
			if (l2 != NULL && l2->next)
				l2 = l2->next;
			else
				l2 = NULL;
		}//while

		ListNode *curNode = resNode->next;
		while (curNode->next)
		{
			if (curNode->val > 9)
			{
				curNode->next->val += (curNode->val) / 10;
				curNode->val %= 10;
			}
			curNode = curNode->next;
		}//while
		if (curNode->val > 9)
		{
			curNode->next = new ListNode(curNode->val / 10);
			curNode->val = (curNode->val) % 10;
		}
		return resNode->next;
	}//addTwoNumbers
	
};

int main()
{
	ListNode *a1 = new ListNode(1);
	a1->next = new ListNode(8);
	ListNode *b1 = new ListNode(0);

	Solution so;
	so.addTwoNumbers(a1, b1);

}