#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;
int kasenum;

string str;
double power, volt, curr;
int pos[3];
char ch;

double scan(int index)
{
	bool flag = false;
	double res = 0.0, frac = 0.0, ratio = 0.1, multi = 1;

	if ('-' == str[index])
		flag = true;
	else if (str[index] >= '0' && str[index] <= '9')
		res = str[index] - '0';
	index++;

	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + str[index] - '0';
		index++;
	}
	if ('.' == str[index])
	{
		index++;
		while (str[index] >= '0' && str[index] <= '9')
		{
			frac = frac + ratio * (str[index] - '0');
			index++;
			ratio *= 0.1;
		}
	}
	res += frac;

	switch (str[index])
	{
	case 'm':
		multi = 1e-3;
		break;
	case 'k':
		multi = 1e+3;
		break;
	case 'M':
		multi = 1e+6;
		break;
	default:
		multi = 1.0;
		break;
	}

	res *= multi;
	return flag ? -res : res;
}


void readInfo()
{
	getline(cin, str);
	pos[0] = str.find('=');
	pos[1] = str.find('=', pos[0] + 1);

	for (int i = 0; i < 2; i++)
	{
		switch (str[pos[i] - 1])
		{
		case 'U':
			volt = scan(pos[i] + 1);
			break;
		case 'I':
			curr = scan(pos[i] + 1);
			break;
		case 'P':
			power = scan(pos[i] + 1);
			break;
		}
	}
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kasenum);
	getchar();
	int kase = 0;
	while (kasenum--)
	{
		power = -1;
		volt = -1;
		curr = -1;
		readInfo();
		
		printf("Problem #%d\n", ++kase);
		if (-1 == power)
			printf("P=%.2lfW\n", volt * curr);
		else if (-1 == volt)
			printf("U=%.2lfV\n", power / curr);
		else
			printf("I=%.2lfA\n", power / volt);
		printf("\n");
	}
	return 0;
}