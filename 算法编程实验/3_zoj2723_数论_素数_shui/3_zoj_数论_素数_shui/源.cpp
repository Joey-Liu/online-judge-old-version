#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 1000000 + 10;
int num_prime = 0;
int isNotPrime[maxn] = { 1, 1 };
int prime[maxn];

void make_prime()
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
	}// for int i
}

int N;
int main()
{
	make_prime();
	while (1 == scanf("%d", &N))
	{
		bool flag = false;
		for (int i = 0; prime[i] <=  N/2; i++)
		{
			if (0 == N % prime[i])
			{
				if (!isNotPrime[N / prime[i]])
				{
					printf("Yes\n");
					flag = true;
					break;
				}
			}
		}

		if (!flag)
			printf("No\n");
	}
	return 0;
}