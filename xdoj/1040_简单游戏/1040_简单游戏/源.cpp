#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;
int casenum;
double a, b, c, x, y, z;
const int maxn = 100000;

int main()
{
	cin >> casenum;
	while (casenum--)
	{
		cin >> x >> y >> z;
		a = (x + y - z) / 2;
		b = (x - y + z) / 2;
		c = (y - x + z) / 2;
		if (a < 1 || a > maxn || b < 1 || b > maxn || c < 1 || c > maxn)
			cout << "Impossible" << endl;
		else
			cout << a << " " << b << " " << c << endl;
	}
}
