#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 8;

int board[maxn][maxn];
int visited[maxn][maxn];

int goal_row, goal_col;
int r1, r2, c1, c2;

int dr[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

bool in_map(int r, int c)
{
	if (r < 0 || r >= 8 || c < 0 || c >= 8)
		return false;
	return true;
}

void bfs()
{
	pair<int, int> pa(r1, c1);
	queue<pair<int, int> > que;
	que.push(pa);
	bool flag = false;
	while (!flag && !que.empty())
	{
		pair<int, int> p = que.front();
		que.pop();
		int r = p.first, c = p.second;
		if (r == r2 && c == c2)
			break;

		for (int i = 0; i < 8; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (in_map(nr, nc) && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				board[nr][nc] = board[r][c] + 1;
				pair<int, int> tp(nr, nc);
				que.push(tp);
			}
		}
	}//while
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char ch1, ch2;
	
	while (cin >> ch1 >> r1 >> ch2 >> r2)
	{
		memset(visited, false, sizeof(visited));
		memset(board, 0, sizeof(board));
		c1 = ch1 - 'a';
		c2 = ch2 - 'a';
		r1--; r2--;
		bfs();
		cout << "To get from " << char('a' + c1) << r1 + 1 << " to " << char('a' + c2) << r2 + 1;
		cout << " takes ";
		cout << board[r2][c2] <<" knight moves."<< endl;
	}//while
	return 0;
}