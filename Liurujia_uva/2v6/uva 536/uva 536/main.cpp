#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

struct Node
{
	char ch;
	Node *left;
	Node *right;
	Node()
	{
		left = NULL;
		right = NULL;
	}
};

string preorder, inorder;

Node* work(int plp, int prp, int inlp, int inrp)
{
	if (plp > prp)
		return NULL;
	Node *root = new Node();
	root->ch = preorder[plp];

	int idx = 0;
	while (inorder[idx] != root->ch)
		idx++;
	int lp_size = idx - inlp;
	int rp_size = inrp - idx;

	root->left = work(plp + 1, plp + lp_size, inlp, idx - 1);
	root->right = work(plp + lp_size + 1, prp, idx + 1, inrp);
	return root;
}

void posorder_print(Node *root)
{
	if (!root)
		return;
	if (root->left)
		posorder_print(root->left);
	if (root->right)
		posorder_print(root->right);
	printf("%c", root->ch);
}

void delete_node(Node *root)
{
	if (!root)
		return;
	if (root->left)
		delete_node(root->left);
	if (root->right)
		delete_node(root->right);
	delete root;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> preorder >> inorder)
	{
		Node *root = work(0, preorder.size() - 1, 0, inorder.size() - 1);
		posorder_print(root);
		printf("\n");

	}
	return 0;
}