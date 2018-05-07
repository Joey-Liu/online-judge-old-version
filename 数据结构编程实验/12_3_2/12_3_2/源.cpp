#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <stdio.h>
#include <memory.h>
using namespace std;

const int maxn = 2000 + 100;
char str[maxn][8];
int v[maxn][maxn];
int dis[maxn];
bool used[maxn];

/*
struct node
{
	int num;
	int distance;
	bool used;
	bool operator< (const node & a) const
	{
		return distance > a.distance;
	}
}E[maxn];
*/

//priority_queue<node> Q;
//priority_queue<node> Tmp;

void init(int n)
{
	memset(v,0,sizeof(v));
	for(int i = 0;i < n;i++)
		scanf("%s",str[i]);
	
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			for(int k = 0;k < 7;k++)
				if(str[i][k] != str[j][k])
					v[i][j]++;
}

void solve(int n)
{
	//E[0].used = true;
	//E[0].distance = 0;
	//E[0].num = 0;

	used[0] = true;
	dis[0] = 0;
	for(int i = 1;i < n;i++)
	{
		used[i] = false;
		dis[i] = v[0][i];
		//E[i].num = i;
		//E[i].distance = v[0][i];
	}//各节点到生成树的信息
	/*
	for(int i = 1;i < n;i++)
	{
		if(!E[i].used)//结点未使用时，加入队列
			Q.push(E[i]);
	}
	*/
	int res = 0;
	for(int count =1;count < n;count++)//产生n-1条变
	{
		//res += Q.top().distance;
		//int tmp = Q.top().num;
		//E[Q.top().num].used = true;
		int minsize = 1000;
		int  tmp = 0;
		for(int i = 1;i < n;i++)
		{
			if(dis[i] < minsize && used[i] != true )
			{
				tmp = i;
				minsize = dis[i];
			}
		}
		res += dis[tmp];
		used[tmp] = true;

		for(int i = 1;i < n;i++)
		{
			//if(E[i].used==false && E[i].distance > v[tmp][i])
			//	E[i].distance = v[tmp][i];
			if(used[i]==false && dis[i] > v[tmp][i])
				dis[i] = v[tmp][i];
		}
		
		/*
		while(!Q.empty())
			Q.pop();
		for(int i = 0;i < n;i++)
			if(!E[i].used)
				Q.push(E[i]);
		*/
	}
	//cout<<"The highest possible quality is 1/"<<res<<"."<<endl;
	printf("The highest possible quality is 1/%d.\n",res);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	scanf("%d",&num);
	while(num != 0)
	{
		init(num);
		solve(num);
		scanf("%d",&num);
	}
	return 0;
}