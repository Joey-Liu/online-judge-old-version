#include <iostream>
#include <queue>
#include <map>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int maxn = 1000 + 5;
queue<int> teams;
queue<int> inter_team[maxn];
map<int, int> id;
int team_num;
char cmd[20];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (1 == scanf("%d", &team_num) && team_num)
	{
		printf("Scenario #%d\n", ++kasenum);
		int tid, sid;
		while (!teams.empty())
			teams.pop();
		for (int i = 0; i < maxn; i++)
		{
			while (!inter_team[i].empty())
				inter_team[i].pop();
		}

		for (int i = 0; i < team_num; i++)
		{	
			scanf("%d", &tid);
			for (int j = 0; j < tid; j++)
			{
				scanf("%d", &sid);
				id[sid] = i;
			}
		}

		while (1 == scanf("%s", cmd) && 'S' != cmd[0])
		{
			if ('E' == cmd[0])
			{
				scanf("%d", &sid);
				tid = id[sid];
				if (inter_team[tid].empty())
					teams.push(tid);
				inter_team[tid].push(sid);
			}
			else
			{
				tid = teams.front();
				sid = inter_team[tid].front();
				inter_team[tid].pop();
				if (inter_team[tid].empty())
					teams.pop();
				printf("%d\n", sid);
			}
		}
		printf("\n");
	}//while scanf
	return 0;
}