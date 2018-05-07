#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const double a = 1 + sqrt(2);
const double b = 1 - sqrt(2);
const double c = 2 * sqrt(2);
const int m = 1000000007;

typedef long long LL;

int main()
{
	freopen("out1.txt", "w", stdout);
	LL num[1000];
	num[0] = 0;
	num[1] = 1;

	for (int i = 2; i < 1000; i++)
	{
		num[i] = 2 * num[i - 1] + num[i - 2];
		num[i] %= m;
	}

	for (int i = 0; i < 1000; i++)
		cout << num[i] << endl;
}