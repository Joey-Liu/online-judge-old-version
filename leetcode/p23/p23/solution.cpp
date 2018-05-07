#include <iostream>
#include <vector>
#include <memory>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


struct Node
{
	Node(int a = -1, int b = -1)
	{
		ind = a;
		val = b;
	}
	int ind;
	int val;
};

struct cmp 
{
	bool operator() (Node a, Node b)
	{
		return a.val > b.val;
	}
};

class Solution {
public:
	ListNode * mergeKLists(vector<ListNode*>& lists)
	{
		priority_queue<Node, vector<Node>, cmp > pq;
		for (int i = 0; i < lists.size(); i++)
		{
			if (lists[i])
			{
				Node node(i, lists[i]->val);
				pq.push(node);
			}
		}

		ListNode* ln = new ListNode(-1), *re = ln;
		while (!pq.empty())
		{
			Node node = pq.top();
			pq.pop();
			int ind = node.ind;
			ln->next = lists[ind];
			ln = ln->next;

			lists[ind] = lists[ind]->next;
			if (lists[ind])
			{
				Node n(ind, lists[ind]->val);
				pq.push(n);
			}
		}
		return re->next;
	}//listnode
};