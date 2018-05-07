#include <iostream>
#include <memory.h>
using namespace std;
const int maxn = 25;

int dp[maxn][maxn][maxn];//dp[i][j][k] ��ʾ ��i����� j��Ҷ�ӣ�k��߶�ʱ �ķ�������

int solve(int i,int j,int k)
{
	if(-1 != dp[i][j][k])
		return dp[i][j][k];

	if(0==i || k==0)
	{
		if(i==0 && k==0 && j==0)
			return (dp[i][j][k] = 1);
		else
			return (dp[i][j][k] = 0);
	}
	else if(i==1 || k==1)
	{
		if(i==1 && j==1 && k==1)
			return (dp[i][j][k] = 1);
		else
			return (dp[i][j][k] = 0);
	}
	else
	{
		int res = 0;
		int lp;//�������ڵ�
		int ltl;//������Ҷ�ӽڵ�
		for(lp = 0;lp < i;lp++)//������ lp ��0 -- i- 1��
			for(ltl = 0;ltl <= min(lp,j);ltl++)
				res += solve(lp,ltl,k - 1) * solve(i - lp - 1,j - ltl,k - 1) + solve(lp,ltl,k - 2) * solve(i - lp - 1,j - ltl,k - 1) + solve(lp,ltl,k -1)* solve(i -lp -1,j -ltl,k - 2); 
		
		return (dp[i][j][k] = res);
	}//else
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	int m,n;
	while(cin>>m>>n)
	{
		//memset(dp,-1,sizeof(dp));
		int ans = 0;
		for(int i = 1;i <= 6;i++)//������ɹ���5 ��
			ans += solve(m,n,i);
		cout<<ans<<endl;
	}
	return 0;
}
