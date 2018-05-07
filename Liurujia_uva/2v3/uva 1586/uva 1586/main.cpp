#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

const int maxn = 80 + 20;
char compund_str[maxn];

double get_aw(char ch)
{
	if ('C' == ch)
		return 12.01;
	else if ('H' == ch)
		return 1.008;
	else if ('O' == ch)
		return 16.00;
	else
		return 14.01;
}

double work()
{
	int index = 0, len = strlen(compund_str);
	double aw = 0.0, sum_aw = 0.0;
	while (index < len)
	{
		if (isalpha(compund_str[index]))
		{	
			aw = get_aw(compund_str[index]);
			index++;
		}
		int cnt = 0;
		while (isdigit(compund_str[index]))
		{
			cnt = cnt * 10 + compund_str[index] - '0';
			index++;
		}//while
		if (!cnt)
			cnt = 1;
		sum_aw += aw * cnt;
	}//while
	return sum_aw;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		scanf("%s", compund_str);
		printf("%.3f\n", work());
	}//while
	return 0;
}