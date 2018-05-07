#include <iostream>
using namespace std;

const int maxn = 100 + 10;
bool use[maxn];
int dist[maxn];//到生成树之间距离
int map[maxn][maxn];
int num;
int res = 0;

void init()
{
	for(int i = 0;i < num;i++)
		for(int j = 0;j < num;j++)
			cin>>map[i][j];

	memset(use,false,sizeof(use));
	use[0] = true;

	memset(dist,100,sizeof(dist));
	for(int i = 1;i < num;i++)
		dist[i] = map[0][i];

	res = 0;
}

void Prim()
{
	for(int i = 1;i < num;i++)
	{
		int tmp = 0;
		for(int k = 1;k < num;k++)
			if(dist[k] < dist[tmp] && !use[k])
				tmp = k;

		use[tmp] = true;
		res += dist[tmp];
		for(int j = 1;j < num;j++)
			if(!use[j] && map[tmp][j] < dist[j])
				dist[j] = map[tmp][j];
	}//for int i
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num)
	{
		init();
		Prim();
		cout<<res<<endl;
	}
	return 0;
}