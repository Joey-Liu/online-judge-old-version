#include <iostream>
using namespace std;

const int maxn = 300 + 50;
int map[maxn][maxn];
bool visited[maxn];
int pre[maxn];
int n,m;

bool dfs(int i)
{
	for(int j = 1;j < maxn;j++)
	{
		if(!visited[j] && map[i][j])
		{
			visited[j] = true;
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>n)
	{
		memset(map,false,sizeof(map));
		for(int i = 1;i <= n;i++)
		{
			int p,q,t,time;
			cin>>t;
			for(int j = 0;j < t;j++)
			{
				cin>>p>>q;
				time = (p - 1) * 12 + q;
				map[i][time] = true;
			}
		}//for int i

		int res = 0;
		memset(pre,0,sizeof(pre));
		for(int i = 1;i <= n;i++)
		{
			memset(visited,false,sizeof(visited));
			if(dfs(i))
				res++;
		}
		cout<<res<<endl;
	}//while n
	return 0;
}