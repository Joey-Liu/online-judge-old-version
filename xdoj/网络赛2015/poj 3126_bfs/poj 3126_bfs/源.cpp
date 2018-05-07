#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;

const long maxn = 1000000 + 10;
int prime[maxn] = { 0 };//基于0  
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };//合数为 1， 素数为0
int step[maxn];				//step[i]表示 到达i数字时所用的步奏

void makePrime()
{
	for (int i = 2; i < maxn; i++)//依次枚举各个数字  
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;

		//进行线性筛除  
		for (long j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;//把小于 i 的素数 和 i 的乘积置为合数这里可以分为两种情况 1.i是素数  2.i不是素数  
			if (!(i % prime[j]))//只筛除不大于 其最小质因数 与 i 的乘积  
				break;
		}
	}
}


int change(int x, int i, int j)	//将x 的第i位 改为 j
{
	if (1 == i)
		return (x / 10) * 10 + j;
	if (2 == i)
		return (x / 100) * 100 + j * 10 + x % 10;
	if (3 == i)
		return (x / 1000) * 1000 + j * 100 + (x % 100);
	if (4 == i)
		return x % 1000 + j * 1000;
}

struct node
{
	int k;
	int step;
};
queue <node> que;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	makePrime();
	int casenum, ans;
	cin >> casenum;

	while (casenum--)
	{
		int st, en;
		cin >> st >> en;
		while (que.size() != 0)
			que.pop();


		node begin;
		begin.k = st;
		begin.step = 0;
		bool hasFind = false;
		que.push(begin);
		memset(step, 100, sizeof(step));	//初始化为无穷大
		step[begin.k] = 0;
		ans = 0;

		while (que.size() != 0)
		{
			node cur = que.front();
			que.pop();

			if (cur.k == en)
			{
				hasFind = true;
				ans = cur.step;
				break;
			}
			
			//开始探索路径
			int tk, ts;
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					if (i == 4 && j == 0)		//不满足题意
						continue;
					
					tk = change(cur.k, i, j);
					if (isNotPrime[tk])			//不是素数
						continue;

					ts = cur.step + 1;
					if (ts > step[tk])		//说明之前访问过
						continue;
					step[tk] = ts;

					if (tk == en)
					{
						hasFind = true;
						ans = step[tk];
						break;
					}

					node tmp;
					tmp.k = tk; tmp.step = ts;
					que.push(tmp);
				}//for int j
			}//for int i

			if (hasFind || que.size() == 0)
				break;
		}//while

		if (hasFind)
			cout << ans << endl;
		else
			cout << "Impossible" << endl;
	}//while true
	return 0;
}