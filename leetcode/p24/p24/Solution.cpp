#include <iostream>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * swapPairs(ListNode* head)
	{
		ListNode *cur = head, *prev = NULL, *nxt = NULL;
		while (cur)
		{
			nxt = cur->next;

		}
	}
};