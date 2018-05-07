#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
long long int ind = 0;
int a = 0;

bool isPerfect()
{
	long long int ind_t = ind;
	int res = 0;
	while (ind_t)
	{
		res += (ind_t % 10);
		ind_t /= 10;
	}
	if (10 == res)
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int k;
	scanf("%d", &k);
	while (a < k)
	{
		ind++;
		if (isPerfect())
			a++;
	}
	printf("%I64d \n", ind);
}