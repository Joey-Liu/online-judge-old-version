#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;
const int maxn = 1000000 + 10;
int su[maxn];
int num_su[maxn];
bool u[maxn];
int num = 1;

void prime()
{
	memset(u,true,sizeof(u));
	u[0] = u[1] = false;
	for(int i = 2;i < maxn;i++)
	{
		if(u[i])
		{
			for(int j = 2;i * j < maxn;j++)
				u[i * j]  = false;
		}
	}
	for(int i = 2;i < maxn;i++)
		if(u[i])
			su[num++] = u[i];
}

int sum_of_digit(int num)
{
	int tmp,res = 0;
	while(num > 0)
	{
		tmp = num % 10;
		res += tmp;
		num /= 10;
	}
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,lp,rp,res;
	memset(num_su,0,sizeof(num_su));
	prime();

	for(int i = 2;i < maxn;i++)
		if(u[i] && u[sum_of_digit(i)])
			num_su[i] = 1;
	for(int i = 2;i < maxn;i++)
		num_su[i] += num_su[i - 1];
	
	scanf("%d",&casenum);
	while(casenum--)
	{
		scanf("%d%d",&lp,&rp);
		res = num_su[rp] - num_su[lp];
		if(u[lp])
			res++;
		printf("%d\n",res);
	}
	return 0;
}