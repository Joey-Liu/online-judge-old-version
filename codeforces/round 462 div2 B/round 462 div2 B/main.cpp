#include <iostream>

using namespace std;

typedef long long LL;
const LL maxn = 1e18;

int main()
{
	int k;
	cin >> k;
	if (k > 36)
		cout << -1 << endl;
	else
	{
		while (k > 0)
		{
			if (k > 1)
			{
				cout << 8;
				k -= 2;
			}
			else
			{
				cout << 4;
				k -= 1;
			}
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}