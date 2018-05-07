#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>

using namespace std;

const long maxn = 1000000 + 10;
int prime[maxn] = { 0 };//����0  
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };//����Ϊ 1�� ����Ϊ0
int step[maxn];				//step[i]��ʾ ����i����ʱ���õĲ���

void makePrime()
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


int change(int x, int i, int j)	//��x �ĵ�iλ ��Ϊ j
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
		memset(step, 100, sizeof(step));	//��ʼ��Ϊ�����
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
			
			//��ʼ̽��·��
			int tk, ts;
			for (int i = 1; i <= 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					if (i == 4 && j == 0)		//����������
						continue;
					
					tk = change(cur.k, i, j);
					if (isNotPrime[tk])			//��������
						continue;

					ts = cur.step + 1;
					if (ts > step[tk])		//˵��֮ǰ���ʹ�
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