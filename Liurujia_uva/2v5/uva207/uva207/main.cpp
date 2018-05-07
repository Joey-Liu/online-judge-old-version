#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 144 + 20;
struct PLAYER
{
	string name;
	int round_score[4];
	bool amateur;
	bool dq;
	int place;
	double money;
};

PLAYER players[maxn];
double purse, percents[70];

int main()
{
	int kase, kasenum = 0;
	scanf("%d", &kase);
	while (kasenum++ < kase)
	{

	}//while
}