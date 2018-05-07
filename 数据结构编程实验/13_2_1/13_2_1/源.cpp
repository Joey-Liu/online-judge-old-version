#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 60;
bool map[maxn][maxn];

int p;//运送货物
char source,destination;

int translation(int num)//A 为 1 a 为 27
{
	if(num < 'a')
		return (num - 'A' + 1);
	return (num - 'a' + 27);
}
void init(int n)
{
	memset(map,false,sizeof(map));
	char c1,c2;
	for(int i =0;i < n;i++)
	{
		cin>>c1>>c2;
		int a = translation(c1);
		int b = translation(c2);
		map[a][b] = true;
		map[b][a] = true;
	}
}

int solve(int stuff,int from,int to)
{
	int g[maxn];//各个节点处所剩下的货物
	bool flag[maxn];
	
	memset(g,-1,sizeof(g));//各节点货物数量初始为-1
	memset(flag,false,sizeof(flag));//各个节点均在队列中

	g[from] = stuff;

	while(true)
	{
		int next = -1;//队列中最短路径编号
		int w = 0;//暂存结点最大货物数量

		//找到货物数量最大的结点
		for(int i = 1;i <= maxn;i++)
		{
			if(!flag[i] && (next == -1 || w < g[i]))
			{
				next = i;
				w = g[i];
			}
		}
		
		if(-1==next)
			break;
		flag[next] = true;//从队列中删除
		for(int i = 1;i < maxn;i++)//对各个节点货物数量进行更新
		{
			if(map[next][i])
				g[i] = max( i < 27 ? w - (w - 1)/20 - 1 : w - 1,g[i]);
		}
	}//while true
	return g[to];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	int n;
	while(cin>>n && n != -1)
	{
		init(n);
		cin>>p>>source>>destination;

		int so =translation(source);
		int des = translation(destination);

		int lp =1,rp = 1000000;
		while(lp + 1< rp)
		{
			int mid = (lp + rp)/2;
			int rest = solve(mid,so,des);
			if(rest >= p)
				rp = mid;
			else
				lp = mid;
		}//2 分
		if(solve(lp,so,des)==p)
			cout<<"Case "<<casenum++<<": "<<lp<<endl;
		else
			cout<<"Case "<<casenum++<<": "<<rp<<endl;
	}
	return 0;
}