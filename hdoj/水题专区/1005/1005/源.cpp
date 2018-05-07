#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int a, b, n;
const int maxn = 10000;
int num[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> a >> b >> n;
	while (a || b || n)
	{
		num[1] = num[2] = 1;
		int i;
		for (i = 3; i < maxn; i++)
		{
			num[i] = a * num[i - 1] + b * num[i - 2];
			num[i] %= 7;
			if (num[i] == 1 && num[i - 1] == 1)
				break;
		}

		//说明 序列是以i-2 为周期的
		n = n % (i - 2);
		if (0 == n)
			cout << num[i - 2] << endl;
		else
			cout << num[n] << endl;
		cin >> a >> b >> n;
	}//while
	return 0;
}