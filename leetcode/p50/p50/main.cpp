#include <math.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
INT_MIN
double myPow(double x, long long n) {
	double t = x, res = 1;
	bool flag = (n > 0 ? true : false);
	long long N = abs(n);
	while (N > 0) {
		if (N & 1) {
			res *= t;
		}
		t = t * t;
		N = N >> 1;
	}
	if (flag)
		return res;
	return 1.0 / res;
}

int main()
{
	long long a = -2147483647;
	a -= 1;
	double res = myPow(2.00000, a);
	return 0;
}