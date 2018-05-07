#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;

const long maxn = 1000000 + 10;
int prime[maxn] = { 0 };//����0  
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };	// ����Ϊ1������Ϊ0
int step[maxn];						//step[i] ��ʾ����i��Ҫ���ٲ�
int ans;							//answer

void make()
{
	for (int i = 2; i < maxn; i++)//����ö�ٸ�������  
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;

		//��������ɸ��  
		for (long j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;//��С�� i ������ �� i �ĳ˻���Ϊ����������Է�Ϊ������� 1.i������  2.i��������  
			if (!(i % prime[j]))//ֻɸ�������� ����С������ �� i �ĳ˻�  
				break;
		}
	}
}

struct node
{
	int k;
	int step;			//��ǰ����Ϊk��·������Ϊstep
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
		memset(step, 100, sizeof(step));//step��ʼ��Ϊ�����
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
				if (0 == i)	//ʹ�ü�һ
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
				else if (1 == i)	//����������
				{
					for (int j = 0; prime[j] <= cur.k; j++)
					{
						if (0 == cur.k % prime[j])
						{
							tk = cur.k / prime[j];
							ts = cur.step + 1;
							if (step[tk] < ts)			//֮ǰ�Ѿ����ʹ�
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