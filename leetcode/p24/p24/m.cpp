#include <iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

void rever(ListNode *ln)
{
	if (NULL == ln->next)
		return;
	ListNode *t = ln->next;
	rever(t);
	t->next = ln;
	ln->next = NULL;
}

class Solution {
public:
	ListNode * ReverseList(ListNode* pHead)
	{
		ListNode *ln = pHead;
		while (ln->next)
			ln = ln->next;
		rever(pHead);
		return ln;
	}
};

int main()
{
	ListNode *head = new ListNode(-1), *cur = head;
	for (int i = 0; i < 1000; i++)
	{
		ListNode * ln = new ListNode(i);
		cur->next = ln;
		cur = cur->next;
	}
	Solution sol;
	ListNode* t = sol.ReverseList(head);
	while (t)
	{
		cout << t->val << " ";
		t = t->next;
	}
	int a;
	cin >> a;
	return 0;
}