#include <iostream>
#include <stdio.h>
using namespace std;

int RiseTree(int s)
{
	char c;
	int v;//�ڵ�Ȩֵ
	scanf("%c",&c);
	while(c != '(')
		scanf("%c",&c);

//	while( ' '==(c = getchar()) || '\n'==(c = getchar()))
//		continue;
	c = getchar();
	while(' '==c || '\n'==c)
		c = getchar();
	//scanf("%c",&c);
	if(c != ')')//˵�����յ�������
	{
		ungetc(c,stdin);//�˻ص���׼���
		scanf("%d",&v);
	}
	else 
		return -2;//��㲻����,���ڱ�ʶҶ�ӽڵ�
	int Lf = RiseTree(s - v);
	int Rf = RiseTree(s - v);
	while((c = getchar()) != ')');
	if(Rf==-2 && Lf==-2 && s==v)//���Ҿ���Ҷ�Ӷ���������
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