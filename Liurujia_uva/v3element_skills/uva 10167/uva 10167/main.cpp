#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 50 + 10;
const int LIMIT = 50;
int coords[maxn][2];
int N, a, b;


bool work()
{
	int rs = 0;
	for (int i = 0; i < 2 * N; i++)
	{
		int tmp = a * coords[i][0] + b * coords[i][1];
		if (!tmp)
			return false;
		else if (tmp > 0)
			rs++;
	}
	if (rs == N)
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N)
	{
		bool flag = false;
		for (int i = 0; i < 2 * N; i++)
			cin >> coords[i][0] >> coords[i][1];

		for (int i = -500; i <= 500; i++)
		{
			for (int j = -500; j <= 500; j++)
			{
				a = i;
				b = j;
				flag = work();
				if (flag)
					break;
			}
			if (flag)
				break;
		}
		cout << a << " " << b << endl;
	}//while
	return 0;
}