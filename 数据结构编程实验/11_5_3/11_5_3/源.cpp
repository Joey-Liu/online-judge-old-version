#include <iostream>
using namespace std;

const int maxn = 100 + 10;
int map[maxn][maxn];
int pre[maxn];
int queue[maxn];
int tot;
int num;//节点个数

void init()
{
	memset(map,0,sizeof(map));
	memset(pre,0,sizeof(pre));

	int tson;
	for(int i =	1;i <= num;i++)
	{
		cin>>tson;
		while(0 != tson)
		{
			map[i][tson] = 1;
			pre[tson]++;
			cin>>tson;
		}
	}//for
	memset(queue,-1,sizeof(queue));
	tot = 0;
}

void solve()
{
	for(int i = 1;i <= num;i++)
	{
		if(0==pre[i])
			queue[tot++] = i;
	}

	for(int i = 0;i < tot;i++)
	{
		cout<<queue[i]<<" ";
		for(int j = 1;j <= num;j++)
		{
			if(1==map[queue[i]][j])
			{
				pre[j]--;
				if(0==pre[j])
					queue[tot++] = j;
			}
		}//for int j
	}//for int i
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>num;
	init();
	solve();
	return 0;
}