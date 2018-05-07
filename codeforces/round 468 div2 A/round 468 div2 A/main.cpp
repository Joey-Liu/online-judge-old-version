#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		if (a > b)
			swap(a, b);
		int d = b - a;
		int k = d / 2;
		int tire = (1 + k) * k;
		if (d % 2)
			tire = tire + (d + 1) / 2;
		cout << tire << endl;
	}
}