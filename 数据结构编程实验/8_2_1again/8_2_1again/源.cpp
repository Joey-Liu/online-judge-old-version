#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 100000 + 10;
int set[maxn + maxn ];//�������������˼·�����a��b�Ƕ������ɣ�����߰����ôa��b + n��b�Ķ������ɣ���ͬһ���ɣ�b �� a+n��a�Ķ������ɣ���ͬһ����

int set_find(int d)
{
	if(set[d] < 0)
		return d;
	return set[d] = set_find(set[d]);
}

int main()
{
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(set,-1,sizeof(set));//ÿ�����Լ�����һ������
		char c[5];
		int a,b;
		for(int i = 0;i < m;i++)
		{
			scanf("%s%d%d",c,&a,&b);
			if('A'==c[0])
			{
				if(set_find(a) != set_find(b) && set_find(a) != set_find(b + n))//���a b����ͬһ���ɣ���aҲ����b�Ķ������ɣ���Ŀǰ����ȷ��
					printf("Not sure yet.\n");
				else if(set_find(a) == set_find(b))
					printf("In the same gang.\n");
				else
					printf("In different gangs.\n");
			}
			else
			{
				if(set_find(a) != set_find(b + n))//��δ���ð���
				{
					set[set_find(a)] = set_find(b + n);//a�İ�����Ϊb�Ķ�������
					set[set_find(b)] = set_find(a + n);//b�İ�����Ϊa�Ķ�������
				}

			}
		}
		
	}//while
	return 0;
}