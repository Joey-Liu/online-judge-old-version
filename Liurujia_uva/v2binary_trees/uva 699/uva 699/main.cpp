#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
const int maxn = 300 + 150;
int num, ans[maxn];

typedef struct Tnode
{
	int value;
	Tnode *lp;
	Tnode *rp;
} Node;

Node* newNode()
{
	Node *np = new Node;
	np->lp = NULL;
	np->rp = NULL;
	np->value = 0;
	return np;
}

void buildTree(Node *parent)
{
	//left son
	cin >> num;
	if (num == -1)
		parent->lp = NULL;
	else
	{
		Node *np = newNode();
		parent->lp = np;
		np->value = num;
		buildTree(np);
	}

	//right son
	cin >> num;
	if (-1 == num)
		parent->rp = NULL;
	else
	{
		Node *np = newNode();
		parent->rp = np;
		np->value = num;
		buildTree(np);
	}
}

void work(Node* np, int pos)
{
	ans[pos] += np->value;
	if (np->lp != NULL)
		work(np->lp, pos - 1);
	if (np->rp != NULL)
		work(np->rp, pos + 1);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (cin>>num)
	{
		if (num < 0)
			break;
		
		Node *root = newNode();
		root->value = num;
		buildTree(root);
		memset(ans, 0, sizeof(ans));

		work(root, maxn / 2);
		int i = 0;
		while (i < maxn)
		{
			if (ans[i])
				break;
			i++;
		}
		cout << "Case " << ++kasenum << ":" << endl << ans[i];

		for (++i; i < maxn; i++)
		{
			if (!ans[i])
				continue;
			cout << " " << ans[i];
		}
		cout << endl << endl;
	}//while
	return 0;
}