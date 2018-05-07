#include <iostream>
#include <stdio.h>
using namespace std;

int RiseTree(int s)
{
	char c;
	int v;//节点权值
	scanf("%c",&c);
	while(c != '(')
		scanf("%c",&c);

//	while( ' '==(c = getchar()) || '\n'==(c = getchar()))
//		continue;
	c = getchar();
	while(' '==c || '\n'==c)
		c = getchar();
	//scanf("%c",&c);
	if(c != ')')//说明接收到了数字
	{
		ungetc(c,stdin);//退回到标准输出
		scanf("%d",&v);
	}
	else 
		return -2;//结点不可用,用于标识叶子节点
	int Lf = RiseTree(s - v);
	int Rf = RiseTree(s - v);
	while((c = getchar()) != ')');
	if(Rf==-2 && Lf==-2 && s==v)//左右均无叶子而自身满足
		return 1;
	else if(Rf==1 || Lf==1)
		return 1;
	else
		return 0;
}

int main()
{
	freopen("112.in","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	while(1==scanf("%d",&num))
	{
		if(1==RiseTree(num))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}