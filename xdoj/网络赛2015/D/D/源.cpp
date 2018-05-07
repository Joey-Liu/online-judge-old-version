#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

const int maxn = 100;
int bin[maxn];

int mod_exp(int a, int b, int n)
{
	int d = 1;
	int index = 0;
	int tmp = b;

	while (tmp != 0)
	{
		bin[index++] = tmp % 2;
		tmp /= 2;
	}

	index--;

	for (int i = index; i >= 0; i--)
	{
		d = (d * d) % n;
		if (bin[i] == 1)
			d = (d * a) % n;
	}
	return d;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, b, n;
	while (cin >> a >> b >> n)
	{
		cout << mod_exp(a, b, n) << endl;
	}
	return 0;
}