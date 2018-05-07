#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long LL;

const int maxn = 20;
int poker[maxn];
LL casenum, cardnum,ans;


int card(char ch)
{
	if (ch - '0' >= 2 && ch - '0' <= 9)
		return (ch - '0');
	else if ('T' == ch)
		return 10;
	else if ('J' == ch)
		return 11;
	else if ('Q' == ch)
		return 12;
	else if ('K' == ch)
		return 13;
	return 1;
}

LL factor(int n)
{
	LL res = 1;
	for (int i = 1; i <= n; i++)
		res *= i;
	return res;
}


void work()
{
	string str;
	for (int i = 0; i < cardnum; i++)
	{
		cin >> str;
		poker[card(str[0]) ]++;
	}
}

bool check(string str)
{
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i]==str[i - 1])

	}
}

int main()
{
	
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> casenum;

	for (int cnt = 1; cnt <= casenum; cnt++)
	{
		memset(poker, 0, sizeof(poker));
		cin >> cardnum;

		ans = factor(cardnum);
		work();
		
		LL inerqpl = 1, kindnum = 0, exc = 1;
		for (int i = 0; i < maxn; i++)
		{
			if (poker[i] != 0)
				kindnum++;
		}
		/*
		if (cardnum > 1)
		{
			for (int i = 0; i < maxn; i++)
			{
				if (poker[i] == 0 || poker[i] == 1)
					continue;
				else
					inerqpl = inerqpl * factor(poker[i]);
			}//for int i
			
			if (inerqpl != 1)
			{
				exc = factor(kindnum);
				exc *= inerqpl;
				ans = ans - exc;
			}
		}*/

		for (int i = 0; i < maxn; i++)
		{

		}
		cout << "Case #" << cnt << ": " << ans << endl;

	}//for;
	return 0;
}












