#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x = -1) :val(x), next(NULL)
	{}
};

class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k)
	{
		int len = 0;
		ListNode *ln = head;
		while (ln)
		{
			len++;
			ln = ln->next;
		}//while
		if (len < k)
			return head;

		ln = head;
		for (int i = 0; i < k - 1; i++)
			ln = ln->next;

		ListNode *cur = head, *prev = NULL, *nxt = NULL;
		ListNode *blhead = NULL, *bltail = NULL;
		for (int i = 0; i < len; i += k)
		{
			prev = NULL;
			if (i + k > len)
			{
				bltail->next = cur;
				break;
			}

			blhead = cur;
			int ind = 0;
			while (ind < k)
			{
				nxt = cur->next;
				cur->next = prev;
				prev = cur;
				cur = nxt;
				ind++;
			}//while ind < k
			if (bltail)
				bltail->next = prev;
			bltail = blhead;
			blhead->next = NULL;
		}//for int i
		return ln;
	}
};

int main()
{
	ListNode *h = new ListNode(), *cur = h;
	for (int i = 1; i < 6; i++)
	{
		ListNode *t = new ListNode(i);
		cur->next = t;
		cur = cur->next;
	}
	cur = h->next;
	Solution sol;
	sol.reverseKGroup(cur, 2);

	int k;
	cin >> k;
	return 0;
}