#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int n;

int main()
{
	while (cin >> n)
	{
		double mi = n * log10(n);
		int intpart = int(mi + 1e-7);
		double fract = mi - intpart;
		if (fract < 0)
			fract = 0.0;

		int ans = (int)(pow(10, fract) + 1e-7);
		cout << ans << endl;
	}

	return 0;
}