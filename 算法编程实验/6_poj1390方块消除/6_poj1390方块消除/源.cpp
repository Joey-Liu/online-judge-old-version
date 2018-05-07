#include <iostream>
using namespace std;

const int maxn = 200 + 50;

int color[maxn];
int length[maxn];//基于1 存储
int after[maxn];//后继颜色相同的最多的方块数量
int seq[maxn];//input
int cnum;//颜色区块数量
int dp[maxn][maxn][maxn];//从 第 i块 到第j块，后面有 k块相同色块时的最大分数

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,cas = 1;
	cin>>casenum;
	while(casenum--)
	{
		int num;
		cin>>num;
		
		for(int i = 1;i <= num;i++)
			cin>>seq[i];

		///////////////设置颜色区块
		cnum = 1;
		color[1] = seq[1];
		int tlen = 1;
	
		for(int i = 2;i <= num;i++)
		{
			if(seq[i -1]==seq[i])
				tlen++;
			else
			{
				color[cnum] = seq[i -1];
				length[cnum++] = tlen;
				tlen = 1;
			}
		}
		color[cnum] = seq[num];
		length[cnum] = tlen;

		//统计各个方块后最多可加多少 相同方块
		memset(after,0,sizeof(after));
		for(int i = 1;i < cnum;i++)
		{
			for(int j = i + 2;j <= cnum;j++)
			{
				if(color[i]==color[j])
					after[i] += length[j];
			}
		}

		memset(dp,0,sizeof(dp));
		//自底向上 用长度遍历，与回文字符串相似
		for(int dis = 1;dis <= cnum;dis++)
		{
			for(int lp = 1;lp + dis - 1<= cnum;lp++)
			{
				int rp = lp + dis - 1;
				for(int k = 0;k <= after[rp];k++)//枚举rp后面还有k 个相同字符
				{
					dp[lp][rp][k] = dp[lp][rp - 1][0] + (length[rp] + k) * (length[rp] + k);
					for(int p = lp;p < rp;p++)//枚举中间色块,应该从 lp 处开始
						if(color[p]==color[rp])
							dp[lp][rp][k] = max(dp[lp][rp][k],dp[lp][p][k + length[rp]] + dp[p + 1][rp - 1][0]);

				}//for int k	
			}//for lp
		}//for dis

		cout<<"Case "<<cas++<<":"<<" "<<dp[1][cnum][0]<<endl;
	}//while casenum
	return 0;
}