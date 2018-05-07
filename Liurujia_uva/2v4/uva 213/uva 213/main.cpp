#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = (1 << 8) + 10;
char codes[8][maxn];

bool readcodes()
{
	char c;
	while ((c = getchar()) == '\n')
		continue;

	if (EOF == c)
		return false;
	codes[1][0] = c;
	bool flag = true;
	for (int i = 2; i < 8; i++)
	{
		for (int j = 0; j < (1 << i) - 1; j++)
		{
			c = getchar();
			if ('\n' == c)
			{
				flag = false;
				break;
			}
			codes[i][j] = c;
		}
		if (!flag)
			break;
	}
	return true;
}

int readbi(int n)
{
	int val = 0;
	for (int i = 0; i < n; i++)
	{
		char c = getchar();
		if ('\n' == c)
		{
			i--;
			continue;
		}
		int t = c - '0';
		val = (val << 1) + t;
	}
	return val;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (readcodes())
	{
		while (true)
		{
			int len = readbi(3);
			if (!len)
				break;
			int ind = 0;

			while (true)
			{
				ind = readbi(len);
				if (ind == ((1 << len) - 1))
					break;
				putchar(codes[len][ind]);
			}//while true
		}//while true
		putchar('\n');
	}//while readcodes
	return 0;
}