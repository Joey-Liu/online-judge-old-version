#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 15 + 10;
int size, nu[maxn];

int bsearch(int n, int lp,int rp)
{
	bool flag = false;
	int mid = (lp + rp) / 2;
	while (lp + 1 < rp)
	{
		if (nu[mid] == n)
		{
			flag = true;
			break;
		}
		
		if (nu[mid] < n)
			lp = mid;
		if (nu[mid] > n)
			rp = mid;
		mid = (lp + rp) / 2;
	}
	
	if (flag)
		return mid;
	else
	{
		if (nu[lp] == n)
			return lp;
		if (nu[rp] == n)
			return rp;
		return -1;
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n;
	while (cin >> n)
	{
		if (-1 == n)
			break;
		nu[0] = n;
		size = 1;
		while (cin >> n && n != 0)
			nu[size++] = n;

		sort(nu, nu + size);
		int res = 0;
		for (int i = 0; i < size; i++)
		{
			if (-1 != bsearch(2 * nu[i], i, size - 1))
				res++;
		}
		cout << res << endl;
	}

	return 0;
}