#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;
const int maxn = 50 + 10;

struct BST
{
	char data;
	BST* left;
	BST* right;
	BST* parent;
	BST()
	{
		data = '\0';
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void tree_insert(BST* &root, BST* &z)
{
	BST* y = NULL;
	BST* x = root;

	while (x != NULL)
	{
		y = x;
		if (z->data <= x->data)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (NULL == y)
		root = z;
	else if (z->data <= y->data)
		y->left = z;
	else
		y->right = z;
}

void preorder(BST* root)
{
	if (root != NULL)
	{
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
		delete root -> left;
		delete root->right;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string str[maxn];
	int counter = 0;
	while (true)
	{
		counter = 0;
		while (true)
		{
			cin >> str[counter];
			counter++;
			if (str[counter - 1] == "*" || str[counter - 1] == "$")
				break;
		}

		BST* root = NULL;
		for (int i = counter - 2; i >= 0; i--)
		{
			for (int j = 0; j < str[i].length(); j++)
			{
				BST* tmp = new BST;
				tmp->data = str[i][j];
				tree_insert(root, tmp);
			}//int j
		}//int i
		preorder(root);
		printf("\n");
		delete root;

		if (str[counter - 1] == "$")
			break;
	}
	return 0;
}