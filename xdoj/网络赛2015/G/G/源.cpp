#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 100000 + 10;

int start[maxn];
int en[10];
const double lg2 = log10(2);

void init()
{
	en[0] = 1; en[1] = 2; en[2] = 4; en[3] = 8; en[4] = 6; en[5] = 2;
	start[0] = 1; start[1] = 2; start[2] = 4; start[3] = 8;

	for (int i = 4; i < maxn; i++)
	{
		double fract = i * lg2 - int(i * lg2 + 1e-7);
		start[i] = int(pow(double(10), fract) + 1e-7);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int casenum, num;
	cin >> casenum;
	while (casenum--)
	{
		cin >> num;
		cout << start[num] << " ";
		if (0 == num)
			cout << en[0] << endl;
		else
		{
			num %= 4;
			if (0 == num)
				num = 4;
			cout << en[num] << endl;
		}
	}
	return 0;
}