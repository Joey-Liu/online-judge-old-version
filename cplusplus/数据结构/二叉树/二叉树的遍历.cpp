#include<iostream>
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	char data;
	struct BiTNode *Lchild, *Rchild;
}BiTNode,*BiTree;
void CreateBTree(BiTree &T);
void Preorder(BiTree T);
void Inorder(BiTree T);
void Postorder(BiTree T);
using namespace std;
int main()
{  
	BiTree T=NULL;
	printf("请输入二叉树：");
	CreateBTree(T);
	cout<<"先序："; Preorder(T); cout<<endl;
    cout<<"中序："; Inorder(T);  cout<<endl;
    cout<<"后续："; Postorder(T); cout<<endl;
	system("pause");
	return 0;
}


void CreateBTree(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(' '==ch)		T=NULL;
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))
		{	
			printf("内存不足");
			system("pause");
			exit(1);
		}
		T->data=ch;
		CreateBTree(T->Lchild);
		CreateBTree(T->Rchild);
	}
}

void Preorder(BiTree T)
{
	if(T!=NULL)
	{
		printf("%c ",T->data);
		Preorder(T->Lchild);
		Preorder(T->Rchild);
	}
}

void Inorder(BiTree T)
{
	if(T!=NULL)
	{
		Inorder(T->Lchild);
		printf("%c ",T->data);
		Inorder(T->Rchild);
	}
}
void Postorder(BiTree T)
{
	
	if(T!=NULL)
	{
		Postorder(T->Lchild);
		Postorder(T->Rchild);
		printf("%c ",T->data);
	}
}
