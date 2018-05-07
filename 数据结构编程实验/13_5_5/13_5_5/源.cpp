#include <iostream>
#include <stdio.h>
using namespace std;

const int maxn = 100 + 10;
double map[maxn][maxn];

int n,m;
void init()
{
//	memset(map,-1,sizeof(map));
	for(int i = 0;i < maxn;i++)
		for(int j = 0;j < maxn;j++)
			map[i][j] = -1.0;
	int a,b;
	double pro;
	for(int i = 1;i <= m;i++)
	{
		scanf("%d%d%lf",&a,&b,&pro);
		//cin>>a>>b>>pro;
		map[a][b] = pro/100;
		map[b][a] = pro/100;
	}
}

void solve()
{
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++)
				if(i != j && i != k && j != k)
					if(-1==map[i][j] && map[i][k] > 0 && map[k][j] > 0)
						map[i][j] = map[i][k] * map[k][j];
					else if(map[i][j] < map[i][k] * map[k][j] && map[i][k] > 0 && map[k][j] > 0)
						map[i][j] = map[i][k] * map[k][j];

	double res = 100 * map[1][n];
	printf("%.6lf percent\n",res);

}

int main()
{
	freopen("chicago.in","r",stdin);
	freopen("out.txt","w",stdout);
	//cin>>n;
	scanf("%d",&n);
	while(n > 0)
	{
		scanf("%d",&m);
		init();
		solve();
		scanf("%d",&n);
	}
	return 0;
}