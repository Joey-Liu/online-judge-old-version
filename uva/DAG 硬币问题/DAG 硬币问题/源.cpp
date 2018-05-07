#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define INF 0x3f3f3f3f

using namespace std;
const int maxn = 1000 + 10;
int val[maxn];
int coinKinds;
int g[maxn], f[maxn];	//g用来求最长路径 f用来求最短路径
bool visG[maxn];
bool visF[maxn];
int money;

int dpg(int S)
{
	int & ans = g[S];
	if (visG[S])
		return ans;
	ans = -1 << 30;
	visG[S] = true;

	for (int j = 0; j < coinKinds; j++)
	{
		if (val[j] > S)
			continue;
		ans = max(ans, dpg(S - val[j]) + 1);
	}
	return ans;
}

int dpf(int S)
{
	int & ans = f[S];
	if (visF[S])
		return ans;
	ans = 1 << 30;
	visF[S] = true;
	for (int j = 0; j < coinKinds; j++)
	{
		if (val[j] > S)
			continue;
		ans = min(ans, dpf(S - val[j]) + 1);
	}
	return ans;
}

void print_ans(int d[], int S)
{
	for (int i = 0; i < coinKinds; i++)
	{
		if (val[i] <= S && d[S - val[i]] + 1 == d[S])
		{
			printf("%d ", val[i]);
			print_ans(d, S - val[i]);
			break;
		}
	}
}

int main()
{
	cin >> money;
	cin >> coinKinds;
	for (int i = 0; i < coinKinds; i++)
		cin >> val[i];

	//g[0] = f[0] = 0;
	//for (int i = 1; i <= money; i++)
	//{
	//	g[i] = -INF;
	//	f[i] = INF;
	//}
	//for (int i = 1; i <= money; i++)
	//{
	//	for (int j = 0; j < coinKinds; j++)
	//	{
	//		if (i >= val[j])
	//		{
	//			g[i] = max(g[i], g[i - val[j]] + 1);
	//			f[i] = min(f[i], f[i - val[j]] + 1);
	//		}
	//	}
	//}//for int i
	memset(visF, false, sizeof(visF));
	memset(visG, false, sizeof(visG));
	visF[0] = visG[0] = true;
	f[0] = 0; g[0] = 0;

	dpf(money); dpg(money);
	printf("%d %d\n", g[money], f[money]);
	print_ans(g, money);
	printf("\n");
	print_ans(f, money);
	system("pause");
	return 0;
}