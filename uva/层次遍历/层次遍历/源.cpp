#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

using namespace std;
const int maxn = 3000;
typedef struct Tnode
{
	int have_value;
	int v;
	Tnode *left, *right;
}Node;

Node *root;
bool failed = false;
char s[maxn + 10];

Node* newNode()
{
	Node* u = new Node;
	if (u != NULL)
	{
		u->have_value = 0;
		u->left = u->right = NULL;
	}
	return u;
}

void addNode(int v, char *s)
{
	int n = strlen(s);
	Node* u = root;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L')
		{
			if (u->left == NULL)
				u->left = new Node();
			u = u->left;
		}
		else if (s[i] == 'R')
		{
			if (u->right == NULL)
				u->right = newNode();
			u = u->right;
		}
	}
	if (u->have_value)
		failed = true;
	u->v = v;
	u->have_value = 1;
}

int n = 0, ans[maxn];
int bfs()
{
	int front = 0, rear = 1;
	Node *q[maxn];
	q[0] = root;
	while (front < rear)
	{
		Node* u = q[front++];
		if (!u->have_value)
			return 0;
		ans[n++] = u->v;
		if(u->left != NULL)
			q[rear++] = u->left;
		if (u->right != NULL)
			q[rear++] = u->right;
	}
	return 1;
}

void removeTree(Node *u)
{
	if (NULL == u)
		return;
	removeTree(u->left);
	removeTree(u->right);
	delete u;
}

int readInput()
{
	failed = 0;
	root = newNode();
	while (true)
	{
		if (scanf("%s", s) != 1)
			return 0;
		if (!strcmp("()", s))
			break;
		int v;
		sscanf(&s[1], "%d", &v);
		addNode(v, strchr(s, ',') + 1);
	}
	return 1;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (true)
	{
		int res = readInput();
		if (!res)
			return 0;
		else
		{
			int flag = bfs();
			if (!flag)
				printf("-1\n");
			else if (failed)
				printf("failed!\n");
			else
			{
				for (int i = 0; i < n; i++)
					printf("%d ", ans[i]);
			}
		}
	}
	return 0;
}