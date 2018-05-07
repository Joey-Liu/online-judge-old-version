#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Node
{
	int value;
	Node *left;
	Node *right;
	Node()
	{
		value = -1;
		left = NULL;
		right = NULL;
	}
};

vector<int> in_order, post_order;
const int INF = 0x7fffffff;
int weight_res = INF, leaf_res = INF;

Node* construct_tree(int inl, int inr, int pol, int por)
{
	if (inl > inr)
		return NULL;
	Node *p = new Node();
	int rv = post_order[por];
	p->value = post_order[por];

	int idx = inl;
	for (idx = inl; idx <= inr; idx++)
	{
		if (in_order[idx] == rv)
			break;
	}
	int left_tree_size = idx - inl;
	p->left = construct_tree(inl, idx - 1, pol, pol + left_tree_size - 1);
	p->right = construct_tree(idx + 1, inr, pol + left_tree_size, por - 1);
	return p;
}

void pre_order_dfs(Node *p, int val)
{
	if (!p->left && !p->right)
	{
		int t = p->value + val;
		if (t < weight_res || (t == weight_res && p->value < leaf_res))
		{
			weight_res = t;
			leaf_res = p->value;
		}
	}
	else
	{
		int t = val + p->value;
		if (p->left)
			pre_order_dfs(p->left, t);
		if (p->right)
			pre_order_dfs(p->right, t);
	}
}

void free_node(Node *p)
{
	if (!p)
		return;
	if (p->left)
		free_node(p->left);
	if (p->right)
		free_node(p->right);
	delete p;
}

void work()
{
	int len = in_order.size();
	Node *root = construct_tree(0, len - 1, 0, len - 1);
	weight_res = INF;
	leaf_res = INF;
	pre_order_dfs(root, 0);
	free_node(root);
	cout << leaf_res << endl;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str;
	while (getline(cin, str))
	{
		in_order.clear();
		post_order.clear();
		stringstream ss(str);
		int t;
		while (ss >> t)
			in_order.push_back(t);

		ss.str("");
		ss.clear();
		getline(cin, str);
		ss << str;
		while (ss >> t)
			post_order.push_back(t);
		
		work();
	}
	return 0;
}