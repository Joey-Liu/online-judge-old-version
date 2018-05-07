#include <iostream>
#include <stdio.h>

typedef long long LL;
using namespace std;

int main()
{
	LL a, b;
	while (cin >> a >> b)
	{
		while (a && b)
		{
			if (a >= 2 * b)
			{
				a = a % (2 * b);
			}
			else if (b >= 2 * a)
			{
				b = b % (2 * a);
			}
			else
				break;
		}
		cout << a << " " << b << endl;
	}
	return 0;
}