#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>

using namespace std;
const int maxn = 10000 + 100;

int su[maxn];
bool isPrime[maxn];
int suNum = 0;

void makePrime()
{
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < maxn; i++)
	{
		if (isPrime[i])
			su[suNum++] = i;
		for (int j = 0; j < suNum; j++)
		{
			if (i * su[j] >= maxn)
				break;
			isPrime[i * su[j]] = false;
			if (i % su[j] == 0)
				break;
		}
	}
}

int work(int num)
{
	int res = 0;
	int tmp = 0;
	for (int i = 0; su[i] <= num; i++)
	{
		tmp = su[i];
		for (int j = i + 1; su[j] <= num; j++)
		{
			tmp += su[j];
			if (tmp >= num)
				break;
		}//for int j

		if (tmp == num)
			res++;
	}// for int i	t
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	makePrime();
	int num;
	while (cin >> num && num != 0)
	{
		int res = 0;
		res = work(num);
		cout << res << endl;
	}

	return 0;
}