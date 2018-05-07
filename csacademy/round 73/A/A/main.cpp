#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1000 + 6;

int num[maxn], N;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	int cnt[3] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < N;j++)
		{
			if (i == num[j])
				continue;
			else
			{
				int t = num[j];
				while (t != i)
				{
					t = (t + 1) % 3;
					cnt[i]++;
				}
			}
		}
	}
	sort(cnt, cnt + 3);
	cout << cnt[0] << endl;
	return 0;
}