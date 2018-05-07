#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <queue>

using namespace std;

const int maxn = 8;

string s1, s2;
typedef pair<int, int> PI;

int visited[maxn][maxn];
int forw[maxn][maxn], back[maxn][maxn];

const int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool inBoard(PI pi)
{
	if (pi.first < 0 || pi.first >= 8 || pi.second < 0 || pi.second >= 8)
		return false;
	return true;
}

int bfs()
{
	int res = 0;
	PI st, ed;
	st.first = s1[0] - 'a';
	st.second = s1[1] - '1';
	ed.first = s2[0] - 'a';
	ed.second = s2[1] - '1';

	if (st == ed)
		return 0;

	queue<PI> qf, qb;
	qf.push(st); qb.push(ed);
	memset(visited, 0, sizeof(visited));
	memset(forw, 0, sizeof(forw));
	memset(back, 0, sizeof(back));

	visited[st.first][st.second] = 1;
	visited[ed.first][ed.second] = 2;
	forw[st.first][st.second] = 0;
	back[ed.first][ed.second] = 0;
	bool flag = false;

	while (!qf.empty() || !qb.empty())
	{
		if (flag)
			break;

		if (!qf.empty())
		{
			PI pi = qf.front();
			qf.pop();

			for (int i = 0; i < 8; i++)
			{
				PI t;
				t.first = pi.first + dr[i];
				t.second = pi.second + dc[i];
				if (!inBoard(t))
					continue;
				if (!visited[t.first][t.second])
				{
					visited[t.first][t.second] = 1;
					forw[t.first][t.second] = forw[pi.first][pi.second] + 1;
					qf.push(t);
				}
				else if (2 == visited[t.first][t.second])
				{
					res = back[t.first][t.second] + forw[pi.first][pi.second] + 1;
					flag = true;
					break;
				}
			}//for int i
		}//if qf.empty()

		if (flag)
			break;

		if (!qb.empty())
		{
			PI pi = qb.front();
			qb.pop();

			for (int i = 0; i < 8; i++)
			{
				PI t;
				t.first = pi.first + dr[i];
				t.second = pi.second + dc[i];
				if (!inBoard(t))
					continue;
				if (!visited[t.first][t.second])
				{
					visited[t.first][t.second] = 2;
					back[t.first][t.second] = back[pi.first][pi.second] + 1;
					qb.push(t);
				}
				else if (1 == visited[t.first][t.second])
				{
					res = forw[t.first][t.second] + back[pi.first][pi.second] + 1;
					flag = true;
					break;
				}
			}//for int i
		}
	}//while
	return res;
}

int main()
{
	while (cin >> s1 >> s2)
	{
		int res = bfs();
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<res<<" knight moves.\n";
	}
	return 0;
}