#include <iostream>
using namespace std;

const int maxn = 10;
int p[maxn];//矩阵规模
int m[maxn][maxn];//m[i][j] 从i 到j 最少标量乘法次数
int s[maxn][maxn];//间断位置

void dp(int n)
{
	int num = n - 1;//矩阵个数
	memset(m,100,sizeof(m));
	memset(s,-1,sizeof(s));

	for(int i = 1;i <= num;i++)
		m[i][i] = 0;

	for(int len = 2;len <= num;len++)
	{
		for(int i = 1;i <= num - len + 1;i++)//起点
		{
			int j = i + len - 1;//终点
			for(int k = i;k <= j -1;k++)
			{
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if(q < m[i][j])
				{
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}


void print(int i,int j)
{
	if(i==j)
		cout<<i<<" ";
	else
	{
		cout<<"( ";
		print(i,s[i][j]);
		print(s[i][j] + 1,j);
		cout<<") ";
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++)
		cin>>p[i];

	dp(n);
	print(1,n - 1);
	return 0;
}