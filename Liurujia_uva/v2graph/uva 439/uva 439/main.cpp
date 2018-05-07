#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <queue>

using namespace std;
const int CBS = 8;
struct Node
{
	int r;
	int c;
};

queue<Node> bq;
string s1, s2;
bool visited[CBS][CBS];
bool inBoard(int r, int c)
{
	if (r < 0 || r >= CBS || c < 0 || c >= CBS)
		return false;
	return true;
}

int dire[8][2] = {
	{ -2, 1 },
	{-1, 2},
	{1, 2},
	{2, 1},
	{2, -1},
	{1, -2},
	{-1, -2},
	{-2, -1}
};

int steps[CBS][CBS];
void bfs(int sr, int sc, int er, int ec)
{
	memset(visited, 0, sizeof(visited));
	memset(steps, -1, sizeof(steps));
	visited[sr][sc] = true;
	steps[sr][sc] = 0;

	while (!bq.empty())
		bq.pop();

	bool hasFound = false;
	Node ns;
	ns.r = sr;
	ns.c = sc;
	bq.push(ns);
	while (!bq.empty())
	{
		Node n = bq.front();
		bq.pop();
		for (int i = 0; i < 8; i++)
		{
			int nr = n.r + dire[i][0];
			int nc = n.c + dire[i][1];
			if (inBoard(nr, nc) && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				Node tmp;
				tmp.r = nr;
				tmp.c = nc;
				bq.push(tmp);
				steps[nr][nc] = steps[n.r][n.c] + 1;
				if (nr == er && nc == ec)
				{
					hasFound = true;
					break;
				}
			}
		}
		if (hasFound)
			break;
	}//while bq
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> s1 >> s2)
	{
		int sr, sc, er, ec;
		sr = s1[0] - 'a';
		sc = s1[1] - '1';
		er = s2[0] - 'a';
		ec = s2[1] - '1';

		memset(visited, false, sizeof(visited));
		int res = 0;
		if (sr == er && sc == ec)
			res = 0;
		else
		{
			bfs(sr, sc, er, ec);
			res = steps[er][ec];
		}
		cout << "To get from " << s1 << " to " << s2 << " takes " << res << " knight moves." << endl;
	}
	return 0;
}