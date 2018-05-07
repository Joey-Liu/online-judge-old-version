#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 100000 + 10;
int set[maxn + maxn ];//这道题是这样的思路，如果a，b是对立帮派（龙帮，蛇帮），那么a和b + n（b的对立帮派）是同一帮派，b 和 a+n（a的对立帮派）是同一帮派

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
		memset(set,-1,sizeof(set));//每个人自己单独一个帮派
		char c[5];
		int a,b;
		for(int i = 0;i < m;i++)
		{
			scanf("%s%d%d",c,&a,&b);
			if('A'==c[0])
			{
				if(set_find(a) != set_find(b) && set_find(a) != set_find(b + n))//如果a b不是同一帮派，但a也不是b的对立帮派，则目前不能确定
					printf("Not sure yet.\n");
				else if(set_find(a) == set_find(b))
					printf("In the same gang.\n");
				else
					printf("In different gangs.\n");
			}
			else
			{
				if(set_find(a) != set_find(b + n))//还未设置帮派
				{
					set[set_find(a)] = set_find(b + n);//a的帮派设为b的对立帮派
					set[set_find(b)] = set_find(a + n);//b的帮派设为a的对立帮派
				}

			}
		}
		
	}//while
	return 0;
}