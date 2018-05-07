#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 100 + 20;
int leds[maxn][20];
bool rem[20];
int P, N;

bool comp(int a[], int b[], int length)
{
	for (int i = 0; i < length; i++)
	{
		if (rem[i])
			continue;
		if (a[i] != b[i])
			return false;
	}
	return true;
}

bool work(int k)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (comp(leds[i], leds[j], P))
				return false;
		}// for int j
	}//for int i
	return true;
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum, ans = 0;
	cin >> kasenum;
	while (kasenum--)
	{
		ans = 0;
		cin >> P >> N;
		memset(rem, false, sizeof(rem));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < P; j++)
				cin >> leds[i][j];
		}

		for (int i = 0; i < P; i++)
		{
			rem[i] = true;
			if (work(i))
				ans++;
			else
				rem[i] = false;
		}
		
		cout << P - ans << endl;
	}//while
	return 0;
}