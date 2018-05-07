#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <memory>

using namespace std;

inline int readint()
{
	char c = getchar();
	while (!isdigit(c))
		c = getchar();

	int x = 0;
	while (isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}

	return x;
}

int buf[12];
inline void writeint(int num)
{
	int index = 0;
	if (0 == num)
		printf("0");
	else
	{
		while (num)
		{
			buf[index++] = num % 10;
			num = num / 10;
		}

		for (int i = index - 1; i >= 0; i--)
			putchar('0' + buf[i]);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int n, c[110];
	while (n = readint())
	{
		memset(c, 0, sizeof(c));
		for (int i = 0; i < n; i++)
			c[readint()]++;
		bool flag = true;

		for (int i = 1; i <= 100; i++)
		{
			for (int j = 0; j < c[i]; j++)
			{
				if (!flag)
					putchar(' ');
				flag = false;
				writeint(i);
			}
		}

		putchar('\n');
	}
	return 0;
}