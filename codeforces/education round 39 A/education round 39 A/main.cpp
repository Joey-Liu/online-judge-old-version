#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int N, t;
	while (cin >> N)
	{
		int res = 0;
		for (int i = 0; i < N; i++)
		{
			cin >> t;
			if (t < 0)
				t = -t;
			res += t;
		}
		cout << res << endl;
	}
	return 0;
}