#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
		swap(a, b);

	if (a + c <= b)
	{
		cout << 2 * (a + c) << endl;
	}
	else
	{
		int res = 0;
		res = (a + c - b) / 2;
		res += b;
		res *= 2;
		cout << res << endl;
	}
	return 0;
}