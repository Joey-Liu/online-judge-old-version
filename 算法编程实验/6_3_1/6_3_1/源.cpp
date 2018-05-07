#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

const int inf = 1<<20;
const int N = 30;
const int M = 1<<16;

int dp[N][M];//m状态下 最后收集 第n个坚果时的最小步数
int map[N][N];//map[i][j] 坚果i 与j 的距离
int x[N],y[N];//坚果i的坐标,基于 0,(0,0)为出发点坐标

void mmin(int & a,int b)
{
	if(a > b)
		a = b;
}

int mmax(int a,int b)
{
	if(a > b)
		return a;
	return b;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int row,col;
	while(cin>>row>>col)
	{
		int num = 0;//坚果数量
		char ch;
		for(int i = 0;i < row;i++)
		{
			for(int j = 0;j < col;j++)
			{
				cin>>ch;
				if('L'==ch)
				{
					x[0] = i;
					y[0] = j;
				}
				else if('#'==ch)
				{
					x[++num] = i;
					y[num] = j;
				}
			}//for int j
		}//for int i
		if(0==num)
		{
			cout<<'0'<<endl;
			continue;
		}
		for(int i = 0;i <= num;i++)
			for(int j = 0;j <= num;j++)
				map[i][j] = mmax(abs(x[i] - x[j]),abs(y[i] - y[j]));//设置各个距离
		int maxz = (1<<num) - 1;//所有坚果均被收集的状态值

		//各个状态初始化
		for(int i = 0;i <= maxz;i++)
			for(int j = 0;j <= num;j++)
				dp[j][i] = inf;

		//收集第一个坚果时 的最小步数
		for(int i = 1;i <=num;i++)
			dp[i][1<<(i - 1)] = map[0][i];

		for(int i = 0;i <= maxz;i++)//枚举所有状态
		{
			for(int j = 1;j <= num;j++)
			{
				if(0 != (i & (1<<(j - 1 ) )))//枚举收集的最后一个坚果j , 注意 参数为（j - 1）!!!!!!!!!!!!!!
				{
					for(int k = 1;k <= num;k++)//从最后的 j 坚果开始 ，枚举 未收集的坚果 k，产生最小步数
					{
						if(0== (i & (1<<(k - 1))) )
							mmin(dp[k][i + (1<<(k - 1))],dp[j][i] + map[j][k]);
					}
				}

			}//for int j
		}//for int i

		int res = inf;
		for(int i = 1;i <= num;i++)
			mmin(res,dp[i][maxz] + map[0][i]);//从全部收集的状态下 ，枚举最后收集为i 的最小步数
		cout<<res<<endl;
	}//while cin>>
	return 0;
}