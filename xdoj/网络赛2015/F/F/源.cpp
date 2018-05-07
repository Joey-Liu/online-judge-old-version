#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;

const long maxn = 1000000 + 10;
int prime[maxn] = { 0 };//基于0  
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };	// 合数为1，素数为0
int step[maxn];						//step[i] 表示到达i需要多少步
int ans;							//answer

void make()
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

struct node
{
	int k;
	int step;			//当前数字为k，路经长度为step
	node(int tk, int ts)
	{
		k = tk;
		step = ts;
	}
};

queue<node> que;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	make();
	
	int num;
	while (cin >> num)
	{
		memset(step, 100, sizeof(step));//step初始化为无穷大
		step[num] = 0;

		if (1 == num)
		{
			cout << "0" << endl;
			continue;
		}

		while (que.size() != 0)
			que.pop();

		node start(num,0);
		que.push(start);
		bool hasFind = false;

		while (que.size() != 0 && !hasFind)
		{
			node cur = que.front();
			que.pop();

			if (cur.k == 1)
			{
				hasFind = true;
				break;
			}

			int tk, ts;
			for (int i = 0; i < 2; i++)
			{
				if (0 == i)	//使用减一
				{
					tk = cur.k - 1;
					ts = cur.step + 1;
					if (step[tk] < ts)
						continue;

					step[tk] = ts;
					if (1 == tk)
					{
						hasFind = true;
						ans = ts;
						break;
					}
					que.push(node(tk, ts));
				}
				else if (1 == i)	//除以素因子
				{
					for (int j = 0; prime[j] <= cur.k; j++)
					{
						if (0 == cur.k % prime[j])
						{
							tk = cur.k / prime[j];
							ts = cur.step + 1;
							if (step[tk] < ts)			//之前已经访问过
								continue;
							
							step[tk] = ts;
							if (1 == tk)
							{
								hasFind = true;
								ans = step[tk];
								break;
							}

							que.push(node(tk, ts));
						}//if
					}
				}//else if
			}//for int i
		}//while que.size
		cout << ans << endl;
	}//while cin>>num
	return 0;
}