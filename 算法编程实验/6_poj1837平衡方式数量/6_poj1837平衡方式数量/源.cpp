#include <iostream>
using namespace std;

const int maxn = 15000 + 100;
int dp[25][maxn];//dp[i][j] ʹ��ǰi������ʱ ƽ���Ϊj �ķ�������
int C,G;
int h[25];//����λ��
int g[25];//����

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>C>>G;
	
	for(int i = 1; i<= C;i++)
		cin>>h[i];
	for(int i = 1;i <= G;i++)
		cin>>g[i];

	memset(dp,0,sizeof(dp));
	dp[0][7500] = 1;

	for(int i = 1;i <= G;i++)
	{
		for(int j = -7500;j <= 7500;j++)
		{
			if(dp[i - 1][j + 7500] != 0)//����״̬����ʱ,������Ӧ�µ�״̬����dfs ���ѽ�ʡ����ʱ��
			{
				for(int k = 1;k <= C;k++)
					dp[i][j + 7500 + g[i] * h[k]] += dp[i - 1][j + 7500];
			}
		}//for int j
	}//for int i
	cout<<dp[G][7500]<<endl;
	return 0;
}