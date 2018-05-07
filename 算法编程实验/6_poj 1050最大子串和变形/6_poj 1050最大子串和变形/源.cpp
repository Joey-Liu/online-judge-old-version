//思路：求最大子矩阵和的时候, 思路是取出两行i, j, 把这两行之间同一列的都加起来形成另外一个数组,
//求这个数组的最大子段和,
//求出来的这个和, 就是这两行之间高度为i - j的子矩阵中最大的和。
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 100 + 20;

int size;
int mat[maxn][maxn];
int sum[maxn];			//记录两行之间 mat[i][k]  mat[j][k]之间的和

int work(int num[])			//计算 数组num的最大子串,没有使用数组 进行
{
	int ans = 0, a = 0;			//a记录之前的 部分有用和（ > 0）相当于 dp[i] = max(num[i], dp[i - 1] + num[i])
	for (int i = 0; i < size; i++)
	{
		if (a > 0)
			a += num[i];
		else
			a = num[i];
		if (a > ans)
			ans = a;
	}
	return ans;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int ans = 0,tmp = 0;
	while (cin >> size)
	{
		ans = 0, tmp = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				cin >> mat[i][j];
		}

		for (int i = 0; i < size; i++)			//开始
		{
			memset(sum, 0, sizeof(sum));
			for (int j = i; j < size; j++)		//结束位置
			{
				for (int k = 0; k < size; k++)
					sum[k] += mat[j][k];
				tmp = work(sum);
				if (tmp > ans)
					ans = tmp;
			}//int j
		}//for  int i
		cout << ans << endl;
	}//while cin
	return 0;
}