#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	int N, a, b;
	while (cin >> N >> a >> b)
	{
		int depth = 0, cn = 1;
		while (cn != N)
		{
			cn = (cn << 1);
			depth++;
		}

		a = pow(2, depth) + a - 1;
		b = pow(2, depth) + b - 1;

		int res = 0;
		while (a != b)
		{
			a = (a >> 1);
			b = (b >> 1);
			res++;
		}
		if (res == depth)
			cout << "Final!" << endl;
		else
			cout << res << endl;
	}
	return 0;
}