#include <iostream>
#include <string>
using namespace std;

const int maxn = 100 + 10;
int dp[maxn][maxn];//dp[i][j] 从 i 到 j 的最少括号数量
string ans[maxn][maxn];//从 i 到 j的匹配字符串
char str[maxn];//从 1 存储

int search(int lp,int rp)
{
	if(dp[lp][rp] != -1)
		return dp[lp][rp];
	//边界
	if(lp ==rp)
	{
		dp[lp][rp] = 1;
		if(str[lp]=='(' || str[lp]==')')
			ans[lp][rp] = "()";
		else
			ans[lp][rp] = "[]";
		return 1;
	}
	if(lp > rp)
	{
		return 0;
	}

	int mark = 0,minum = 1000000;
	int record = -1;
	int tmp;
	for(int k = lp;k < rp;k++)
	{
		tmp = search(lp,k) + search(k+1,rp);
		if(tmp < minum)
		{
			record = k;
			minum = tmp;
			mark = 1;
\		}
	}

	if((str[lp]=='(' && str[rp]==')') || (str[lp]=='[' && str[rp]==']')) 
	{
		tmp = search(lp + 1,rp - 1);
		if(tmp < minum)
		{
			minum = tmp;
			mark = 2;
		}
	}
	if(1==mark)
		ans[lp][rp] = ans[lp][record] + ans[record + 1][rp];
	else
		ans[lp][rp] = str[lp] + ans[lp + 1][rp - 1] + str[rp];
	//记录集
	dp[lp][rp] = minum;
	return minum;
}

int main()
{
//	freopen("bracket.08","r",stdin);
//	freopen("out.txt","w",stdout);
	cin>>str + 1;
	
	int n = strlen(str + 1);
	memset(dp,-1,sizeof(dp));
	for(int i = 0;i <= n;i++)
		for(int j = 0;j <= n;j++)
			ans[i][j] = "";
	search(1,n);
	cout<<ans[1][n]<<endl;
	
	return 0;
}