#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;

typedef struct Tnode
{
	int color;//0 for white, 1 for black, -1 for parent. -2 for not sure
	Tnode* sons[4];
}Node;

const int maxn = 1024 * 2 + 1000;
char treeStrfi[maxn], treeStrse[maxn], ch;

Node* newNode()
{
	Node * u = (Node *)malloc(sizeof(Node));
	if (u != NULL)
	{
		u->color = -2;
		for (int i = 0; i < 4; i++)
			u->sons[i] = NULL;
	}
	return u;
}

void buildTree(Node *parent)
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%c", &ch);
		Node *node = newNode();

		if ('p' == ch)
		{
			node->color = -1;
			buildTree(node);
		}
		else if ('e' == ch)
			node->color = 0;
		else
			node->color = 1;

		parent->sons[i] = node;
	}
}

int count(Node *n, int level)
{
	int res = 0;
	if (-1 == n->color)
	{
		for (int i = 0; i < 4; i++)
			res += count(n->sons[i], level + 1);
	}
	else if (1 == n->color)
		res = pow(4, 5 - level);
	return res;
}

int work(Node* ron, Node *sto, int level) // these two nodes are in same level
{
	int ans = 0;
	if (ron->color == 1)
		ans =  int(pow(4, 5 - level));
	else if (sto->color == 1)
		ans =  int(pow(4, 5 - level));
	else if (ron->color == 0 && sto->color == -1)
		ans = count(sto, level);
	else if (sto->color == 0 && ron->color == -1)
		ans = count(ron, level);
	else if (sto->color == 0 && ron->color == 0)
		ans = 0;
	else
	{
		for (int i = 0; i < 4; i++)
			ans += work(ron->sons[i], sto->sons[i], level + 1);
	}

	return ans;
}

void removeTree(Node * n)
{
	if (n == NULL)
		return;
	if (n->color != -1)
		free(n);
	else
	{
		for (int i = 0; i < 4; i++)
			removeTree(n->sons[i]);
		free(n);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		getchar();
		Node *rootFi = newNode();
		scanf("%c", &ch);

		if ('p' == ch)
		{
			rootFi->color = -1;
			buildTree(rootFi);
		}
		else if ('e' == ch)
			rootFi->color = 0;
		else
			rootFi->color = 1;
		
		getchar();
		Node *rootSe = newNode();
		scanf("%c", &ch);
		if ('p' == ch)
		{
			rootSe->color = -1;
			buildTree(rootSe);
		}
		else if ('e' == ch)
			rootSe->color = 0;
		else
			rootSe->color = 1;

		int res = work(rootFi, rootSe, 0);
		printf("There are %d black pixels.\n", res);
		removeTree(rootFi);
		removeTree(rootSe);
	}//while
	return 0;
}