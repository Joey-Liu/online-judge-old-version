#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;

int mapping(char c)
{
	int res = -1;
	switch (c)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':
		res = 1;
		break;
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S':
	case 'X':
	case 'Z':
		res = 2;
		break;

	case 'D':
	case 'T':
		res = 3;
		break;
	case 'L':
		res = 4;
		break;
	case 'M':
	case 'N':
		res = 5;
		break;
	case 'R':
		res = 6;
		break;
	default:
		res = -1;
	}//switch

	return res;
}

const int maxn = 20 + 15;
char str[maxn];

void solve()
{
	int nu = -1, pre = -2;
	pre = mapping(str[0]);
	if (pre != -1)
		printf("%d", pre);
	for (int i = 1; i < strlen(str); i++)
	{
		nu = mapping(str[i]);
		if (nu == pre)
			continue;
		else if (nu == -1)
		{
			pre = nu;
			continue;
		}
		else
		{
			printf("%d", nu);
			pre = nu;
		}
	}
	printf("\n");
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (EOF != scanf("%s", str))
	{
		solve();
	}
	return 0;
}