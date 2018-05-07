#include <iostream>
using namespace std;

const int maxn = 100 + 50;

int len1,len2;
int dp[maxn][maxn];//dp[i][j] gene1 i 与 gene2 j的最大匹配值
int s[200][200];//存储得分矩阵
char g1[maxn],g2[maxn];

void init()  
{  
     s['A']['A'] = s['C']['C'] = s['G']['G'] = s['T']['T'] = 5;  
     s['A']['C'] = s['C']['A'] = s['A']['T'] = s['T']['A'] = -1;  
     s['A']['G'] = s['G']['A'] = s['C']['T'] = s['T']['C'] = -2;  
     s['G']['T'] = s['T']['G'] = s['G']['-'] = s['-']['G'] = -2;  
     s['A']['-'] = s['-']['A'] = s['C']['G'] = s['G']['C'] = -3;  
     s['T']['-'] = s['-']['T'] = -1;  
     s['C']['-'] = s['-']['C'] = -4;  
}  

int solve()
{
	dp[0][0] = 0;//把两条基因的开始位置认为是有很多空格
	dp[0][1] = s['-'][g2[1]];
	dp[1][0] = s[g1[1]]['-'];

	//这里与在LIS中不同，0 与 前i项 的相似值不为0
	for(int i = 1;i < len2;i++)
		dp[0][i] = dp[0][i - 1] + s['-'][g2[i]];
	for(int i = 1;i < len1;i++)
		dp[i][0] = dp[i-1][0] + s[g1[i]]['-'];
	for(int i = 1;i <= len1;i++)
		for(int j = 1;j <= len2;j++)
			dp[i][j] = max(dp[i - 1][j -1] + s[g1[i]][g2[j]] ,max(dp[i -1][j] + s[g1[i]]['-'],dp[i][j-1] + s['-'][g2[j]] ) );

	return dp[len1][len2];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		cin>>len1>>(g1 + 1)>>len2>>(g2 + 1);
		cout<<solve()<<endl;
	}
	return 0;
}
