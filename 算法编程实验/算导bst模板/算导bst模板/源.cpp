#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct BST
{
	int key;
	BST* left;
	BST* right;
	BST* parent;
	BST()
	{
		key = -1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

/*
BST* tree_search(BST* pt, int k)
{
	if (pt == NULL || k == pt->key)
		return pt;
	if (k < pt->key)
		return tree_search(pt->left, k);
	return tree_search(pt->right, k);
}
*/

BST* tree_search(BST* pt, int k)
{
	while (pt != NULL && k != pt->key)
	{
		if (k < pt->key)
			pt = pt->left;
		else
			pt = pt->right;
	}
	return pt;
}


BST* tree_minimum(BST* pt)
{
	while (pt->left != NULL)
		pt = pt->left;
	return pt;
}

BST* tree_maximum(BST* pt)
{
	while (pt->right != NULL)
		pt = pt->right;
	return pt;
}

BST* tree_successor(BST* pt)//当前节点后继
{
	if (pt->right != NULL)
		return tree_minimum(pt->right);
	
	BST* father = pt->parent;
	while (father != NULL && father->right == pt)
	{
		pt = father;
		father = father->parent;
	}
	return father;
}

void tree_insert(BST* pt, BST* z)
{
	BST* y = NULL;
	BST* x = pt;

	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NULL)//z为树根
		pt = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
}

void transplant(BST* pt,BST* u, BST* v)//用节点v 代替节点u
{
	if (u->parent == NULL)//树根
		pt = v;
	else if (u = u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

void tree_delete(BST* pt, BST* z)
{
	if (z->left == NULL)
		transplant(pt, z, z->right);
	else if (z->right == NULL)
		transplant(pt, z, z->left);
	else
	{
		BST* y = tree_minimum(z->right);
		if (y->parent != z)
		{
			transplant(pt, y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(pt, z, y);
		y->left = z->left;
		y->left->parent = y;
	}
}

void inorder(BST* pt)
{
	if (pt != NULL)
	{
		inorder(pt->left);
		cout << pt->key << " ";
		inorder(pt->right);
	}
}

int main()
{
	//freopen
	freopen("out.txt", "w", stdout);
	BST* root = new BST;
	root->key = 13;
	root->parent = NULL;


	for (int i = 0; i < 13; i++)
	{
		BST* p = new BST;
		int tmp = rand() % 30;
		p->key = tmp;

		tree_insert(root, p);
	}
	inorder(root);
	return 0;
}