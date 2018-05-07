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
	KEY			max_limit;					//�洢�ýڵ� ���������� ������ �˵�
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

	// ���������ж�����һ�������A->parent = NULL�����
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
	// ���������ж�����һ�������A->parent = NULL�����
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
|        ��������:�Բ���keyֵ֮�������������
|        �������:���ڵ�root,����Ľ��z
|        ���ز���:���ڵ�root
-------------------------------------------------------------*/
PRBTree RB_InsertNode_Fixup(PRBTree root, PRBTree z)
{
	PRBTree y;
	while (root != z && RED == z->parent->color)        // ��z���Ǹ�ͬʱ���ڵ����ɫ��red
	{
		if (z->parent == z->parent->parent->left)        // ���ڵ����游�ڵ��������
		{
			y = z->parent->parent->right;                        // yΪz�Ĳ����ڵ�
			if (NULL != y && RED == y->color)                // �����ڵ��������ɫ��red
			{
				z->parent->color = BLACK;                        // ����z�ĸ��ڵ���ɫ��B
				y->color = BLACK;                                        // ����z�Ĳ����ڵ���ɫ��B
				z->parent->parent->color = RED;                // ����z���游�ڵ���ɫ��B
				z = z->parent->parent;                                // ����zΪ�����游�ڵ�
			}
			else                                                                        // �޲����ڵ���߲����ڵ���ɫ��b
			{
				if (z == z->parent->right)                        // ����½ڵ��Ǹ��ڵ��������
				{
					z = z->parent;
					Left_Rotate(z, root);
				}
				z->parent->color = BLACK;                        // �ı丸�ڵ���ɫ��B
				z->parent->parent->color = RED;                // �ı��游�ڵ���ɫ��R
				Right_Rotate(z->parent->parent, root);
			}
		}
		else                                                                                // ���ڵ�Ϊ�游�ڵ��������
		{
			y = z->parent->parent->left;                        // yΪz�Ĳ����ڵ�
			if (NULL != y && RED == y->color)                // ���y����ɫ��red
			{
				z->parent->color = BLACK;                        // ���ĸ��ڵ����ɫΪB
				y->color = BLACK;                                        // ���Ĳ����ڵ����ɫ��B
				z->parent->parent->color = RED;                // �����游�ڵ���ɫ��R
				z = z->parent->parent;                                // ����zָ���游�ڵ�
			}
			else                                                                        // y�����ڻ�����ɫ��B
			{
				if (z == z->parent->left)                        // ����Ǹ��ڵ��������
				{
					z = z->parent;
					Right_Rotate(z, root);
				}
				z->parent->color = BLACK;                        // �ı丸�ڵ����ɫ��B
				z->parent->parent->color = RED;                // �ı��游�ڵ����ɫ��RED
				Left_Rotate(z->parent->parent, root);
			}
		}
	} // while(RED == z->parent->color)

	// ���ڵ����ɫʼ�ն���B
	root->color = BLACK;

	return root;
}


/*-----------------------------------------------------------
|        ��������:�����в���keyֵ
|        �������:���ڵ�root,��������Ĺؼ�ֵkey
|        ���ز���:���ڵ�root
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

	// �õ�z�ĸ��ڵ�, ���KEY�Ѿ����ھ�ֱ�ӷ���
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

	// ����z����������Ϊ�ղ�����ɫ��red��ע���²���Ľڵ���ɫ����red
	z->parent = y;
	z->left = z->right = NULL;
	z->color = RED;

	// �Ժ������������
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