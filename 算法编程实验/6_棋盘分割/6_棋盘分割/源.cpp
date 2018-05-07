#include <iostream>
#include <math.h>

#define MIN(a, b) a>b?b:a
using namespace std;

const int limit = 9;
const int maxn = 15;

int dp[maxn][limit][limit][limit][limit];//dp[k][x1][y1][x2][y2]还有k次切割 在两坐标范围内
int sum[limit][limit];//sum[x][y] (x,y) 到 （0,0）矩形范围的值

int N;//切割次数
int total;//总棋盘值

void init()
{
	int val;
	memset(sum,0,sizeof(sum));
	for(int i  = 1;i < limit;i++)
	{
		for(int j = 1;j < limit;j++)
		{
			scanf("%d", &val);
			sum[i][j] = val + sum[i- 1][j] + sum[i][j - 1] - sum[i - 1][j -1];
		}
	}
	total = sum[8][8];
}

int getsum(int x1,int y1,int x2,int y2)//(x2,y2)到(x1,y1)的值 水平方向为x !!!!!!!!
{
	return (sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1]);
}

int solve(int k,int x1,int y1,int x2,int y2)
{
	if(dp[k][x1][y1][x1][y2] != -1)
		return dp[k][x1][y1][x2][y2];

	int tmp = 10000000;//水平切割 或 垂直切割 的大小
	int minum = 10000000;//决定水平 切割 或 垂直切割
	if(0==k)
	{
		tmp = getsum(x1,y1,x2,y2);
		return (dp[k][x1][y1][x2][y2] = tmp * tmp);
	}
	else
	{
		//垂直切割
		int s1 = 0,s2 = 0;//垂直方向平方值
		int row;
		int a = x1 + 1;
		for(a = x1 + 1;a < x2;a++)
		{
			s1 = getsum(a,y1,x2,y2);//右边矩形值
			s2 = getsum(x1,y1,a,y2);
			
			row = MIN(solve(k - 1,x1,y1,a,y2) +  s1*s1, solve(k-1,a,y1,x2,y2) + s2 * s2);
			tmp = MIN(tmp,row);
		}
		minum = MIN(tmp,minum);

		//水平分割
		int  b = y1 + 1;
		int tro;//每次 枚举选择上下时的最小值
		tmp = 10000000;//tmp重新初始化
		for(b = y1 + 1;b < y2;b++)
		{
			s1 = getsum(x1,b,x2,y2);//下半部分总和
			s2 = getsum(x1,y1,x2,b);//上半部分总和

			
			tro = MIN(solve(k-1,x1,y1,x2,b) + s1*s1 , solve(k -1,x1,b,x2,y2) + s2*s2);
			tmp = MIN(tro,tmp);
		}

		minum = MIN(tmp,minum);
		return (dp[k][x1][y1][x2][y2] = minum);
	}
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d", &N) != EOF)
	{
		init();
		memset(dp,-1,sizeof(dp));
		double test = solve(N -1,0,0,8,8);
		double avg = (double)total / (double)N;
			
		double res = test/(double)N - avg*avg; 
		printf("%.3lf\n", sqrt(res));
	}
	return 0;
}