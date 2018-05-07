#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;
const int maxn = 200 + 20;
int w[maxn];
int f[maxn * maxn];
int Vi, sum, N;
int casenum;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;
	while (casenum--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> w[i];
		
		sum = 0;
		for (int i = 1; i <= N; i++)
			sum += w[i];
		
		Vi = sum / 2;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= N; i++)
		{
			for (int v = Vi; v >= w[i]; v--)
				f[v] = max(f[v], f[v - w[i]] + w[i]);
		}

		int suma = f[Vi];
		int sumb = sum - f[Vi];
		cout << abs(sumb - suma)<<endl;
	}//while casenum--
	return 0;
}