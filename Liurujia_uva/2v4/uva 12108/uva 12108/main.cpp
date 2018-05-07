#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 10 + 10;
const int infinite = 1e6;
struct student
{
	int a, b, c;
	bool asleep;
}stu[maxn];

int stu_num;
bool ohalf_asleep = false;

int check_asleep_num()
{
	int cnt = 0;
	for (int i = 0; i < stu_num; i++)
	{
		if (stu[i].asleep)
			cnt++;
	}
	return cnt;
}

void update_stu_status()
{
	for (int i = 0; i < stu_num; i++)
	{
		stu[i].c = (stu[i].c + 1) % (stu[i].a + stu[i].b);
		if (stu[i].c >= stu[i].a && ohalf_asleep && !stu[i].asleep)
			stu[i].asleep = true;
		else if (stu[i].c >= stu[i].a && !ohalf_asleep && !stu[i].asleep)
		{
			stu[i].asleep = false;
			stu[i].c = 0;
		}
		else if (stu[i].c < stu[i].a)
			stu[i].asleep = false;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (1 == scanf("%d", &stu_num) && stu_num)
	{
		for (int i = 0; i < stu_num; i++)
		{
			scanf("%d%d%d", &stu[i].a, &stu[i].b, &stu[i].c);
			stu[i].a; stu[i].b; stu[i].c--;
			if (stu[i].c >= stu[i].a)
				stu[i].asleep = true;
			else
				stu[i].asleep = false;
		}
		
		int time_p = -1;
		for (int i = 0; i < infinite; i++)
		{
			int cnt = check_asleep_num();
			if (cnt == 0)
			{
				time_p = i + 1;
				break;
			}
			ohalf_asleep = cnt > stu_num / 2;
			update_stu_status();
		}
		
		printf("Case %d: %d\n", ++kasenum, time_p);
	}//while
	return 0;
}