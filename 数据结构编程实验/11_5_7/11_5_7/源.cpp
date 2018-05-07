#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 30;
int map[maxn][maxn];
int cut[maxn][maxn];//传递闭包

int vis[maxn];
int path[maxn];// 路径
int fire;
int cnt = 0;
void floyed()
{
	for(int i = 0;i < maxn;i++)
		for(int j = 0;j < maxn;j++)
			if(map[i][j])
				cut[i][j] = cut[j][i] = true;

	for(int k = 1;k < maxn;k++)
		for(int i = 1;i < maxn;i++)
			for(int j = 1;j < maxn;j++)
				if(cut[i][k] && cut[k][j])
					cut[i][j] = true;
}


void init()
{
	cnt = 0;
	memset(map,false,sizeof(map));
	memset(cut,false,sizeof(cut));
	memset(vis,false,sizeof(vis));

	int m,n;
	cin>>m>>n;
	while(m || n)
	{
		map[m][n] = 1;
		map[n][m] = 1;
		cin>>m>>n;
	}

	floyed();
}

void dfs(int cur,int now)//cur 目前该计算 第cur 个节点，现在位置为 now
{
	if(now==fire)
	{
		cnt++;
		for(int i = 0;i < cur;i++)
		{
			cout<<path[i];
			if(i != cur - 1)
				cout<<" ";
		}
		cout<<endl;
		return;
	}

	for(int i = 2;i < maxn;i++)//回溯
	{
		if(map[now][i] && !vis[i] && cut[i][fire])
		{
			vis[i] = true;
			path[cur] = i;
			dfs(cur + 1,i);
			vis[i] = false;
		}
	}//for int i
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	while(cin>>fire)
	{
		init();
		cout<<"CASE "<<casenum++<<":"<<endl;
		path[0] = 1;
		dfs(1,1);
		cout<<"There are "<<cnt<<" routes from the firestation to streetcorner "<<fire<<"."<<endl;
		cnt = 0;
	}
	return 0;
}