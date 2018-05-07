#include <iostream>
#include <cmath>
using namespace std;

#define MIN(a, b) a>b?b:a

const int size = 9;
const int nMax = 15;
const int inf = 10000000; //我有个小疑惑，不能将inf初始化为0x7fffffff和INT_MAX

int dp[nMax][size][size][size][size];
int sum[size][size]; //记录的是左上角为（1，1）的所有矩形的和

int getSum(int x1, int y1, int x2, int y2) //根据数组sum存储的值求任意矩形的和
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

int cut(int k, int x1, int y1, int x2, int y2)
{
	int s1, s2;
	
	if(dp[k][x1][y1][x2][y2] != -1) //已经求过就可以直接返回了，避免重复运算
		return dp[k][x1][y1][x2][y2];
    if(k == 1)   // k == 1说明切割了n-1次，最后剩下的一块矩形求出其和的平方直接返回
	{
		s1 = getSum(x1, y1, x2, y2);
        return (dp[k][x1][y1][x2][y2] = s1*s1);
	}
    //水平方向切
	int min = inf, tmp1; // min记录横向和纵向切割后，值较小的                    
	for(int x = x1; x < x2; x++)
	{
		s1 = getSum(x1, y1, x, y2);
		s2 = getSum(x+1, y1, x2, y2);
		tmp1 = MIN(cut(k-1, x+1, y1, x2, y2) + s1*s1, cut(k-1, x1, y1, x, y2) + s2*s2); 
		                           //横向将当前的矩形切割为两块后，继续将两块进行切割，最后返回时，选取得到的值较小的
		if(tmp1 < min)
			min = tmp1;                          
	}
	//竖直方向切
	int tmp2;
	for(int y = y1; y < y2; y++)
	{
        s1 = getSum(x1, y1, x2, y);
		s2 = getSum(x1, y+1, x2, y2);
		tmp2 = MIN(cut(k-1, x1, y+1, x2, y2) + s1*s1, cut(k-1, x1, y1, x2, y) + s2*s2);//与横向切割类似
		if(tmp2 < min)
			min = tmp2;
	}
	return (dp[k][x1][y1][x2][y2] = min);
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i, j, val, total, n;
    double avrg;
	
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum)); //必须把sum初始化为0
		total = 0;
		
		for(i = 1; i < size; i++)//注意i，j从1开始
			for(j = 1; j < size; j++)
			{
				scanf("%d", &val);
				total += val;
				sum[i][j] = val + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]; //注意i，j为1时的处理，存储sum[i][j]
			}
		avrg = total*1.0/n;
		
		int res = cut(n, 1, 1, size-1, size-1);
		double ans = sqrt(res*1.0 / n - avrg*avrg); 
		//printf("%d",dec)
		printf("%.3lf\n", ans);
		//system("pause");
	}
	return 0;
}