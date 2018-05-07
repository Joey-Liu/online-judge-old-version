#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;
typedef int data;

enum color{RED,BLACK};

struct RBTREE
{
	data key;
	RBTREE*	left;
	RBTREE* right;
	RBTREE* parent;
	color mark;
	
	RBTREE()
	{
		key = -1;
		left = NULL;
		right = NULL;
		parent = NULL;
		mark = RED;
	}
};

RBTREE* NIL;//哨兵节点

RBTREE* root = NULL;


/////左旋
void left_rotate(RBTREE* x)
{
	RBTREE* y = x->right;
	if (NIL == y)						//根本不用左旋
	{
		cout << "something error." << endl;
		return;
	}

	x->right = y->left;
	if (y->left != NIL)
		y->left->parent = x;
	
	y->parent = x->parent;
	if (NULL == y->parent)				//x为根节点
		root = y;
	else if (x == x->parent->left)		//x为左儿子
		x->parent->left = y;
	else
		x->parent->right = y;			//x为右儿子
	y->left = x;
	x->parent = y;
}

////////右旋
void right_rotate(RBTREE* x)
{
	RBTREE* y = x->left;
	if (NIL == y)
	{
		cout << "something error in right_rotate" << endl;
		return;
	}

	x->left = y->right;
	if (NIL != y->right)
		y->right->parent = x;
	
	y->parent = x->parent;
	if (y->parent == NULL)
		root = y;
	else if (x->parent->left == x)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->right = x;
	x->parent = y;
}

void rb_insert_fixup(RBTREE* z)
{
	while (RED == z->parent->mark)
	{
		if (z->parent == z->parent->parent->left)//父节点是左孩子
		{
			RBTREE* y = z->parent->parent->right;
			if (RED == y->mark)//case 1父节点、叔节点为红色
			{
				z->parent->mark = BLACK;
				y->mark = BLACK;
				z->parent->parent->mark = RED;
				z = z->parent->parent;
			}//case 1
			else if (z == z->parent->right)//节点为右孩子
			{
				z = z->parent;
				left_rotate(z);
			}
			else//节点为左孩子
			{
				z->parent->mark = BLACK;
				z->parent->parent->mark = RED;
				right_rotate(z->parent->parent);
			}
		}//if left son
		else//父节点是右孩子
		{
			RBTREE* y = z->parent->parent->left;
			if (RED == y->mark)
			{
				z->parent->mark = BLACK;
				y->mark = BLACK;
				z->parent->parent->mark = RED;
				z = z->parent->parent;
			}
			//以下的两个左旋、右旋不确定，感觉应该是这样
			else if (z == z->parent->left)
			{
				z = z->parent;
				right_rotate(z);
			}
			else
			{
				z->parent->mark = BLACK;
				z->parent->parent->mark = RED;
				left_rotate(z->parent->parent);
			}
		}//else
	}
	root->mark = BLACK;
	root->parent = NIL;
}

void rb_insert(RBTREE* z)
{
	RBTREE* y = NIL;
	RBTREE* x = root;
	while (x != NIL)
	{
		y = x;
		if (z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == NIL)
		root = z;
	else if (z->key < y->key)
		y->left = z;
	else
		y->right = z;
	z->left = NIL;
	z->right = NIL;
	z->mark = RED;

	root->parent = NIL;
	rb_insert_fixup(z);
}

void in_order_walk(RBTREE *t)
{
	if (t != NIL)
	{
		in_order_walk(t->left);
		cout << t->key << endl;
		in_order_walk(t->right);
	}
}

const int maxn = 10;
int main()
{
	freopen("out.txt", "w", stdout);
	NIL = new RBTREE();
	NIL->left = NULL;
	NIL->right = NULL;
	NIL->key = -1;
	NIL->mark = BLACK;
	root = NIL;

	int num[maxn];
	for (int i = 0; i < maxn; i++)
		num[i] = i;
	for (int i = 0; i < maxn; i++)
	{
		RBTREE *tmp = new RBTREE();
		tmp->key = num[i];
		rb_insert(tmp);
	}

	in_order_walk(root);
	return 0;
}