#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long LL;

const int maxn = 50 + 5;
int N, M;

bool hidden[maxn];
LL tom[maxn], banban[maxn];


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N >> M)
	{
		for (int i = 0; i < N; i++)
			cin >> tom[i];
		for (int i = 0; i < M; i++)
			cin >> banban[i];
		memset(hidden, false, sizeof(hidden));

		LL tres = tom[0] * banban[0], tmp;
		int hindex = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				tmp = tom[i] * banban[j];
				if (tmp >= tres)
				{
					hindex = i;
					tres = tmp;
				}
			}
		}
		
		hidden[hindex] = true;
		LL res = 0;
		bool flag = false;
		for (int i = 0; i < N; i++)
		{
			if (hidden[i])
				continue;
			for (int j = 0; j < M; j++)
			{
				tmp = tom[i] * banban[j];
				if (!flag || tmp > res)
					res = tmp;
				flag = true;
			}
		}
		cout << res << endl;
	}//while
	return 0;
}