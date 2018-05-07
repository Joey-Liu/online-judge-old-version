#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 50;
char str[maxn];

struct Node
{
	int value;
	bool has_value;
	Node *left;
	Node * right;
	Node()
	{
		value = -1;
		has_value = false;
		left = NULL;
		right = NULL;
	}
};

Node *root;
bool valid_flag = true;

void addnode(int val, char *p)
{
	Node *cur = root;
	for (int i = 0; i < strlen(p) - 1; i++)
	{
		if ('L' == p[i])
		{
			if (NULL == cur->left)
				cur->left = new Node();
			cur = cur->left;
		}
		else
		{
			if (NULL == cur->right)
				cur->right = new Node();
			cur = cur->right;
		}
	}
	if (cur->has_value)
		valid_flag = false;
	else
	{
		cur->has_value = true;
		cur->value = val;
	}
}

vector<int> BFS()
{
	queue<Node* > que;
	que.push(root);
	vector<int> res;

	while (!que.empty() && valid_flag)
	{
		Node *p = que.front();
		if (!p->has_value)
		{
			valid_flag = false;
			break;
		}
		res.push_back(p->value);

		que.pop();
		if (p->left)
			que.push(p->left);
		if (p->right)
			que.push(p->right);
	}
	return res;
}

void FreeNode(Node *p)
{
	if (!p)
		return;
	else
	{
		if (p->left)
			FreeNode(p->left);
		if (p->right)
			FreeNode(p->right);
		delete p;
	}
}

bool read()
{
	if (1 != scanf("%s", str))
		return false;
	if (!strcmp(str, "()"))
	{
		if (!valid_flag)
			printf("not complete\n");
		else
		{
			vector<int> res = BFS();
			if (!valid_flag)
				printf("not complete\n");
			else
			{
				for (int i = 0; i < res.size() - 1; i++)
					printf("%d ", res[i]);
				printf("%d\n", res[res.size() - 1]);
			}
		}
		valid_flag = true;
		root = new Node();
		return true;
	}
	else
	{
		int val;
		sscanf(str + 1, "%d", &val);
		char *p = strchr(str, ',');
		addnode(val, p + 1);
		return true;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	root = new Node();
	while (read())
		continue;
	return 0;
}