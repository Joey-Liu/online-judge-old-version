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
	KEY            key;
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
PRBTree RB_InsertNode(PRBTree root, KEY key)
{
	PRBTree x, y;

	PRBTree z;
	if (NULL == (z = (PRBTree)malloc(sizeof(RBTree))))
	{
		printf("Memory alloc error\n");
		return NULL;
	}
	z->key = key;

	// 得到z的父节点, 如果KEY已经存在就直接返回
	x = root, y = NULL;
	while (NULL != x)
	{
		y = x;
		if (key < x->key)
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
		else if (key > x->key)
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

	if (NULL == y || y->key > key)
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
// 中序遍历树, 加了一个判断, 如果输出的数据不满足序列关系就报错退出

void Print_Node(PRBTree node)
{
	char* color[] = { "BLACK", "RED" };
	printf("Key = %d,\tcolor = %s", node->key, color[node->color]);
	if (NULL != node->parent)
		printf(",\tparent = %d", node->parent->key);
	if (NULL != node->left)
		printf(",\tleft = %d", node->left->key);
	if (NULL != node->right)
		printf(",\tright = %d", node->right->key);
	printf("\n");
}
void Mid_Visit(PRBTree T)
{
	if (NULL != T)
	{
		if (NULL != T->left)
		{
			if (T->left->key > T->key)
			{
				printf("wrong!\n");
				exit(-1);
			}
			Mid_Visit(T->left);
		}
		Print_Node(T);
		if (NULL != T->right)
		{
			if (T->right->key < T->key)
			{
				printf("wrong\n");
				exit(-1);
			}
			Mid_Visit(T->right);
		}
	}
}
int main()
{
	srand(time(NULL));
	PRBTree root = NULL;
	int i;
	for (i = 0; i < 100000; i++)
		root = RB_InsertNode(root, rand() % 10000);

	Mid_Visit(root);
	system("pause");
	return 0;
}