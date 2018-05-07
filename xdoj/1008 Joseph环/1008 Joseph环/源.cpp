#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>

using namespace std;
const int maxn = 1000 + 10;
int num[maxn];

int n, k;

int main()
{
	while (cin >> n >> k)
	{
		for (int i = 1; i <= n; i++)
			num[i] = i;

		int w = 1;			//the begin
		do
		{
			w = (w + k - 1) % n;
			if (0 == w)
				w = n;
			cout << num[w];
			if (n != 1)
				cout << " ";
			for (int i = w; i < n; i++)
				num[i] = num[i + 1];
			n--;
		} while (n);
	}
	return 0;
}