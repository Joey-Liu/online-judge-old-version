#include <iostream>
using namespace std;

const int maxn = 1000 + 10;
double f[maxn][40][40];//f[i][j][k] 第i支队伍 在前j道题时做出k 题的概率
double p[maxn][40];//p[i][j] 第i支队伍 做 第j题时的概率
int M,T,N;

void init()
{
	for(int i = 1;i <= T;i++)
		for(int j = 1;j <= M;j++)
			cin>>p[i][j];

	memset(f,0.0,sizeof(f));
	for(int i = 1;i <= T;i++)
	{
		f[i][1][1] = p[i][1];
		f[i][1][0] = 1 - p[i][1];
	}
}

void dp()
{
	for(int i = 1;i <= T;i++)
	{
		for(int j = 2;j <= M;j++)
		{
			for(int k = 0;k <= j;k++)
			{
				if(k==0)
					f[i][j][k] = f[i][j - 1][0] * (1 - p[i][j]);
				else if(k < j)//k <= j存在问题，
					f[i][j][k] = f[i][j - 1][k - 1] * p[i][j] + f[i][j - 1][k] * (1 - p[i][j]);
				else if(k==j)
					f[i][j][k] = f[i][j - 1][k - 1] * p[i][j];
			}
		}//for int j
	}//for int i
}

void solve()
{
	double p1 = 1.0;
	for(int i= 1;i <= T;i++)
		p1 *= (1 - f[i][M][0]);

	double p2 = 1.0,tmp = 0;
	for(int i = 1;i <= T;i++)
	{
		tmp = 0.0;
		for(int j = 1;j <= N -1;j++)
		{
			tmp += f[i][M][j];
		}//for int j
		p2 *= tmp;
	}//for int i
	cout.precision(3);
	cout<<(p1 - p2)<<endl;
	cout.precision(6);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>M>>T>>N;
	while(M || T || N)
	{
		init();
		dp();
		solve();
		cin>>M>>T>>N;
	}
	return 0;
}
