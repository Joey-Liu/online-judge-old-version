#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int divide(int dividend, int divisor)
{
	int sign = (dividend < 0) ^ (divisor < 0);
	if (!divisor || (dividend == INT_MIN && divisor == -1))
		return INT_MAX;
	long long dd = labs(dividend);
	long long dsor = labs(divisor);

	int res = 0;
	while (dd >= dsor)
	{
		long long temp = dsor, t = 1;
		while (dd >= (temp << 1))
		{
			temp <<= 1;
			t <<= 1;
		}
		res += t;
		dd -= temp;
	}
	return (0 == sign ? res : -res);
}

int main()
{
	divide(2147483647, 1);
	return 0;
}