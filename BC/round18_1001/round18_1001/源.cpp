/*注释的在final test 时wrong ==
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

const int maxn = 10000 + 100;
int prime[maxn] = { 0 };
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	for (int i = 2; i < maxn; i++)
	{
		if (!isNotPrime[i])
			prime[num_prime++] = i;
		
		//ɸ
		for (int j = 0; j < num_prime && i * prime[j] < maxn; j++)
		{
			isNotPrime[i * prime[j]] = 1;
			if (!(i % prime[j]))
				break;
		}
	}

	int num,tmp,res = 0;
	while (cin >> num)
	{
		res = 0;
		for (int i = 0; i < num; i++)//num 应该换成maxn...
		{
			for (int j = i; j < num; j++)
			{
				tmp = num - prime[i] - prime[j];
				if (tmp >= 0 && !isNotPrime[tmp] && tmp >= prime[j])
					res++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int maxn = 10000 + 100;
bool prime[maxn];
int ans[maxn];
int num_prime = 0;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	
	for (int i = 2; i < maxn; i++)
	{
		if (prime[i])
		{
			ans[num_prime++] = i;
			for (int k = i * i; k < maxn; k += i)
				prime[k] = false;
		}
	}

	int num;
	while (cin >> num)
	{
		int res = 0;
		for (int i = 0; i < num_prime; i++)
		{
			for (int j = i; j < num_prime; j++)
			{
				int tmp = num - ans[i] - ans[j];
				if (tmp >= 0 && prime[tmp] && tmp >= ans[j])
					res++;
			}
		}
		cout << res << endl;
	}//while
	return 0;
}