#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :val(x), next(NULL) 
	{}
};

class Solution {
public:

	ListNode* ReverseList(ListNode* pHead)
	{
		ListNode *cur = pHead;
		ListNode *prev = NULL;
		ListNode *nxt = NULL;

		while (cur != NULL)
		{
			nxt = cur->next;
			cur->next = prev;
			if (!nxt)
				break;
			prev = cur;
			cur = nxt;
		}
		return cur;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ListNode *head = new ListNode(0);
	ListNode *p = head;
	for (int i = 1; i < 1e5; i++)
	{
		ListNode *ln = new ListNode(i);
		p->next = ln;
		p = p->next;
	}

	p = head;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	
	Solution solution;
	p = solution.ReverseList(head);
	cout << endl;
	while (p != NULL)
	{
		cout << p->val << " ";
		p = p->next;
	}
	cin.get();
}