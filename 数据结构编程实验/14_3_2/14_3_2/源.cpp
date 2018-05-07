#include <iostream>
using namespace std;

const int maxn = 100 + 30;
bool map[maxn][maxn];
bool visited[maxn];
int pre[maxn];
int n,m,k;

bool dfs(int i)//Ñ°ÕÒÔö¹ãÂ·¾¶
{
	for(int j = 1;j <= m;j++)
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
	freopen("input","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n;
	while(n)
	{
		memset(map,false,sizeof(map));
		memset(pre,0,sizeof(pre));
		cin>>m>>k;
		int a,b,res = 0;
		for(int i = 0;i < k;i++)
		{
			cin>>a>>a>>b;
			if(a != 0 && b != 0)
				map[a][b] = 1;
		}//for

		for(int i = 1;i <= n;i++)
		{
			memset(visited,false,sizeof(visited));
			if(dfs(i))
				res++;
		}
		cout<<res<<endl;
		cin>>n;
	}//while
	return 0;
}