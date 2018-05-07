#define _LOCAL
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>
#include <map>

using namespace std;
map<int, int> id2team;
int team_num;
char order[50];

int main()
{
#ifdef _LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int kasenum = 0;
	while (1 == scanf("%d", &team_num) && team_num)
	{
		id2team.clear();
		queue<int> q_mem, q_team[1000 + 20];

		for (int i = 0; i < team_num; i++)
		{
			int tmp, tmp_num;
			scanf("%d", &tmp);
			for (int j = 0; j < tmp; j++)
			{
				scanf("%d", &tmp_num);
				id2team[tmp_num] = i;
			}
		}//for int i

		cout << "Scenario #" << ++kasenum << endl;
		int ele_num, team_num;
		while (true)
		{
			scanf("%s", order);
			if ('E' == order[0])
			{
				scanf("%d", &ele_num);
				team_num = id2team[ele_num];
				if (!q_team[team_num].size())
					q_mem.push(team_num);
				q_team[team_num].push(ele_num);
			}

			else if ('D' == order[0])
			{
				team_num = q_mem.front();
				ele_num = q_team[team_num].front();
				q_team[team_num].pop();
				if (q_team[team_num].empty())
					q_mem.pop();
				cout << ele_num << endl;
			}//
			else
				break;
		}//while true
		cout << endl;
	}//while
	return 0;
}