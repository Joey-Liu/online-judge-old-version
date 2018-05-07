/*
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 10;
int num[maxn];
int casenum;
int length;

int gcd(int a, int b)
{
	if (0 == b)
		return a;
	int t;
	while (0 != b)
	{
		t = a;
		a = b;
		b = t % b;
	}

	return a;
}

int prime[maxn] = { 0 };
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };

void makesu()
{
	for (int i = 2; i < maxn; i++)
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;
		for (int j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int ans = 1, tmp = 1;
	//cin >> casenum;
	makesu();
	scanf("%d", &casenum);
	for (int cnt = 1; cnt <= casenum; cnt++)
	{
		ans = 1, tmp = 1;
		//cin >> length;
		//for (int i = 0; i < length; i++)
		//	cin >> num[i];

		scanf("%d", &length);
		for (int i = 0; i < length; i++)
			scanf("%d", &num[i]);
		
		sort(num, num + length);
		//bool flag = false;

		for (int i = length - 1; i >= 0; i--)
		{
			if (!isNotPrime[num[i]])
				continue;

			for (int j = i - 1; j >= 0; j--)
			{
				if (0 == num[i] % num[j])
				{
					if (ans < num[j])
						ans = num[j];
					break;
				}

				if (0 != num[j] % ans)
					continue;

				tmp = gcd(num[i], num[j]);
				if (tmp > ans)
					ans = tmp;
				if (ans >= num[j])
					break;
			}

			if (ans >= num[i])
				break;
		}//for inti
		//cout << "Case #" << cnt << ": " << ans << endl;

		printf("Case #%d: %d\n", cnt, ans);
	}// for casenum
	return 0;
}
*/

//求n个数中的两个数的最大公约数，
//不用欧几里得（TLE）。在题目给定的范围内不断地增加，
//如果有这个数的倍数，那么他就可能是最大公约数
//tijie(from hdu): 第二种先用cnt计数给定数组，然后倒着枚举答案为d，计算∑k=1105/dcnt[kd]，如果sum≥2，则d就是答案，复杂度为nlogn
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 100;
int casenum, ans, n,num[maxn],mx,tmp;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	int cnt = 1;
	while (casenum--)
	{
		mx = 0;
		memset(num, 0, sizeof(num));
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			num[tmp]++;
			mx = max(mx, tmp);
		}

		for (int i = 1; i <= mx; i++)//i为枚举的因子
		{
			int cnt = 0;
			for (int j = i; j <= mx; j += i)
			{
				if (num[j] > 0)
					cnt += num[j];
			}//for int j
			if (cnt >= 2)		//至少有两个数的公约数是num[j]
				ans = i;
		}//for int i
		cout << "Case #" << cnt++ << ": " << ans << endl;
	}//while
	return 0;
}
