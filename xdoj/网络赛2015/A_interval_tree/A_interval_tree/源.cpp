#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int KEY;

enum NODECOLOR
{
	BLACK = 0,
	RED = 1
};

typedef struct RBTree
{
	struct        RBTree *parent;
	struct      RBTree *left, *right;
	KEY            left_limit, right_limit;
	KEY			id;
	KEY			max_limit;					//存储该节点 所代表子树 的最优 端点
	NODECOLOR   color;
}RBTree, *PRBTree;


/*-----------------------------------------------------------
|   A              B
|  / \    ==>     / \
| a   B           A  y
|    / \         / \
|    b  y        a  b
-----------------------------------------------------------*/
void Left_Rotate(PRBTree A, PRBTree& root)
{
	PRBTree B;
	B = A->right;

	A->right = B->left;
	if (NULL != B->left)
		B->left->parent = A;
	B->parent = A->parent;

	// 这样三个判断连在一起避免了A->parent = NULL的情况
	if (A == root)
	{
		root = B;
	}
	else if (A == A->parent->left)
	{
		A->parent->left = B;
	}
	else
	{
		A->parent->right = B;
	}
	B->left = A;
	A->parent = B;
}

/*-----------------------------------------------------------
|    A              B
|   / \            / \
|  B   y   ==>    a   A
| / \                / \
|a   b              b   y
-----------------------------------------------------------*/
void Right_Rotate(PRBTree A, PRBTree& root)
{
	PRBTree B;
	B = A->left;

	A->left = B->right;
	if (NULL != B->right)
		B->right->parent = A;

	B->parent = A->parent;
	// 这样三个判断连在一起避免了A->parent = NULL的情况
	if (A == root)
	{
		root = B;
	}
	else if (A == A->parent->left)
	{
		A->parent->left = B;
	}
	else
	{
		A->parent->right = B;
	}
	A->parent = B;
	B->right = A;
}



/*-----------------------------------------------------------
|        函数作用:对插入key值之后的树进行修正
|        输入参数:根节点root,插入的结点z
|        返回参数:根节点root
-------------------------------------------------------------*/
PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z)
{
	PRBTree y;
	while (root != z && RED == z->parent->color)        // 当z不是根同时父节点的颜色是red
	{
		if (z->parent == z->parent->parent->left)        // 父节点是祖父节点的左子树
		{
			y = z->parent->parent->right;                        // y为z的伯父节点
			if (NULL != y && RED == y->color)                // 伯父节点存在且颜色是red
			{
				z->parent->color = BLACK;                        // 更改z的父节点颜色是B
				y->color = BLACK;                                        // 更改z的伯父节点颜色是B
				z->parent->parent->color = RED;                // 更改z的祖父节点颜色是B
				z = z->parent->parent;                                // 更新z为它的祖父节点
			}
			else                                                                        // 无伯父节点或者伯父节点颜色是b
			{
				if (z == z->parent->right)                        // 如果新节点是父节点的右子树
				{
					z = z->parent;
					Left_Rotate(z, root);
				}
				z->parent->color = BLACK;                        // 改变父节点颜色是B
				z->parent->parent->color = RED;                // 改变祖父节点颜色是R
				Right_Rotate(z->parent->parent, root);
			}
		}
		else                                                                                // 父节点为祖父节点的右子树
		{
			y = z->parent->parent->left;                        // y为z的伯父节点
			if (NULL != y && RED == y->color)                // 如果y的颜色是red
			{
				z->parent->color = BLACK;                        // 更改父节点的颜色为B
				y->color = BLACK;                                        // 更改伯父节点的颜色是B
				z->parent->parent->color = RED;                // 更改祖父节点颜色是R
				z = z->parent->parent;                                // 更改z指向祖父节点
			}
			else                                                                        // y不存在或者颜色是B
			{
				if (z == z->parent->left)                        // 如果是父节点的左子树
				{
					z = z->parent;
					Right_Rotate(z, root);
				}
				z->parent->color = BLACK;                        // 改变父节点的颜色是B
				z->parent->parent->color = RED;                // 改变祖父节点的颜色是RED
				Left_Rotate(z->parent->parent, root);
			}
		}
	} // while(RED == z->parent->color)

	// 根节点的颜色始终都是B
	root->color = BLACK;

	return root;
}


/*-----------------------------------------------------------
|        函数作用:在树中插入key值
|        输入参数:根节点root,待插入结点的关键值key
|        返回参数:根节点root
-------------------------------------------------------------*/
PRBTree RB_InsertNode(PRBTree root, KEY ll, KEY rl)
{
	PRBTree x, y;

	PRBTree z;
	if (NULL == (z = (PRBTree)malloc(sizeof(RBTree))))
	{
		printf("Memory alloc error\n");
		return NULL;
	}
	//z->key = key;
	z->left_limit = ll;
	z->right_limit = rl;

	// 得到z的父节点, 如果KEY已经存在就直接返回
	x = root, y = NULL;
	while (NULL != x)
	{
		y = x;
		if (ll < x->left_limit)
		{
			if (NULL != x->left)
			{
				x = x->left;
			}
			else
			{
				break;
			}
		}
		else if (ll > x->left_limit)
		{
			if (NULL != x->right)
			{
				x = x->right;
			}
			else
			{
				break;
			}
		}
		else
		{
			return root;
		}
	}

	if (NULL == y || y->left_limit > ll)
	{
		if (NULL == y)
			root = z;
		else
			y->left = z;
	}
	else
	{
		y->right = z;
	}

	// 设置z的左右子树为空并且颜色是red，注意新插入的节点颜色都是red
	z->parent = y;
	z->left = z->right = NULL;
	z->color = RED;

	// 对红黑树进行修正
	return RB_InsertNode_Fixup(root, z);
}




int main()
{
	srand(time(NULL));
	PRBTree root = NULL;
	int i;
	for (i = 0; i < 100000; i++)
		root = RB_InsertNode(root, i,i + 1);

	system("pause");
	return 0;
}