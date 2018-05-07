#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 200 + 50;
struct stone
{
	double x,y;
}node[maxn];

double dis[maxn][maxn];//两节点间距离
bool con[maxn][maxn];//可达性矩阵

void init(int n)
{
	for(int i = 0;i < n;i++)
		cin>>node[i].x>>node[i].y;

	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			dis[i][j] = sqrt(pow(node[i].x - node[j].x,2) + pow(node[i].y - node[j].y,2));
}

void solve(int num,int n)
{
	double lp = 0.0;
	double rp = 5000;
	double mid; 

	while(rp - lp >= 1e-5)
	{
		//先构造关系矩阵
		mid = (lp + rp)/2;
		for(int i =0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(dis[i][j] <= mid)
					con[i][j] = true;
				else
					con[i][j] =	false;
		
		//构造可达性矩阵
		for(int k = 0;k < n;k++)
			for(int i = 0;i < n;i++)
				for(int j = 0;j < n;j++)
					con[i][j] |= con[i][k] & con[k][j];


		if(con[0][1])//在mid跳远距离下能够从0到1
			rp = mid;
		else
			lp = mid;
	}
	printf("Scenario #%d\n",num);
	printf("Frog Distance = %.3lf\n\n",rp);
}

int main()
{
	freopen("frogger.in","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	int n;
	cin>>n;
	while(n != 0)
	{
		init(n);
		solve(casenum++,n);
		cin>>n;
	}
}
