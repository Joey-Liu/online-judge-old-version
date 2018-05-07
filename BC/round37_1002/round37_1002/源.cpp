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

//��n�����е������������Լ����
//����ŷ����ã�TLE��������Ŀ�����ķ�Χ�ڲ��ϵ����ӣ�
//�����������ı�������ô���Ϳ��������Լ��
//tijie(from hdu): �ڶ�������cnt�����������飬Ȼ����ö�ٴ�Ϊd�������k=1105/dcnt[kd]�����sum��2����d���Ǵ𰸣����Ӷ�Ϊnlogn
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

		for (int i = 1; i <= mx; i++)//iΪö�ٵ�����
		{
			int cnt = 0;
			for (int j = i; j <= mx; j += i)
			{
				if (num[j] > 0)
					cnt += num[j];
			}//for int j
			if (cnt >= 2)		//�������������Ĺ�Լ����num[j]
				ans = i;
		}//for int i
		cout << "Case #" << cnt++ << ": " << ans << endl;
	}//while
	return 0;
}
