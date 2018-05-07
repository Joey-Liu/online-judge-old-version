#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 100000 + 10;


string f[maxn];			//f[i]体力 为i时 能够得到的最大数字
int cost[15];			//各个数字 消费的体力值

int strength = 0;
char t1[100], t2[100];

bool less_lower(char c1, char c2)
{
	return c1>c2;
}

string max(string & s1, string & s2)		//保证s1，s2达到各自最大值，返回较大的
{
	//sort(s1.begin(), s1.end(), less<char >());
	//sort(s2.begin(), s2.end(), less<char >());

	if (s1.length() > s2.length())
		return s1;
	else if (s1.length() < s2.length())
		return s2;

	//if (s1 >= s2)
	//	return s1;
	//return s2;
	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (s1[i] > s2[i])
			return s1;
		if (s1[i] < s2[i])
			return s2;
	}
	return s1;
}


void work()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int v = cost[i]; v <= strength; v++)
		{
			char ch = '0' + i;
			string val = f[v - cost[i]] + ch;
			

			//好像可以不用排序,因为后加入的 数字一定比前面大
			//sort(f[i].begin(), f[i].end(), less_lower);
			//sort(val.begin(), val.end(), less_lower);
			f[v] = max(f[v], val);
		}
	}//for int i
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &strength))
	{
		//memset(f, 0, sizeof(f));
		for (int i = 0; i < maxn; i++)
		{
			f[i].clear();
			f[i] = "0";
		}
		for (int i = 1; i < 10; i++)
			scanf("%d", &cost[i]);

		int min = 0x3f3f3f3f;
		for (int i = 1; i < 10; i++)
		{
			if (min > cost[i])
				min = cost[i];
		}

		if (min > strength)
		{
			printf("-1\n");
			continue;
		}

		work();
		if ("0" == f[strength])
			printf("-1");
		else
		{
			for (int i = f[strength].length() - 1; i > 0;i--)
				printf("%c", f[strength][i]);
		}
		printf("\n");
	}
	return 0;
}
