#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 500 + 10;
bool visited[maxn * 2][maxn * 2];
bool obstacle[maxn * 2][maxn * 2];
int m_edge, n_obs, cnt = 0;
int dr[] = { 0, -1, 1, 0 };
int dc[] = { 1, 0, 0, -1 };
char dir[] = "ensw";

bool check(int r, int c, int nr, int nc) {
	int sr = min(r, nr), er = max(r, nr);
	int sc = min(c, nc), ec = max(c, nc);
	
	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (obstacle[i][j])
				return false;
		}
	}
	return true;
}

void dfs(int step, int r, int c, vector<char> & vc, int prev_dir) {
	if (step >= m_edge) {
		if(r == maxn && c == maxn) {
			for (int i = 0; i < vc.size(); i++)
				cout << vc[i];
			cout << endl;
			cnt++;
		}
		return;
	}

	int dist = abs(r - maxn) + abs(c - maxn);
	int sste = 0;
	for (int i = step + 1; i <= m_edge; i++)
		sste += i;
	if (sste < dist)
		return;


	for (int i = 0; i < 4; i++) {
		if (prev_dir == i || prev_dir + i == 3)
			continue;
		int nr = r + dr[i] * (step + 1);
		int nc = c + dc[i] * (step + 1);
		if (!visited[nr][nc] && check(r, c, nr, nc))
		{
			vc.push_back(dir[i]);
			visited[nr][nc] = true;
			dfs(step + 1, nr, nc, vc, i);
			vc.pop_back();
			visited[nr][nc] = false;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--) {
		memset(visited, false, sizeof(visited));
		memset(obstacle, false, sizeof(obstacle));
		cnt = 0;
		
		cin >> m_edge >> n_obs;
		for (int i = 0; i < n_obs; i++) {
			int a, b;
			cin >> a >> b;
			b = -b;
			a += maxn;
			b += maxn;
			obstacle[b][a] = true;
		}
		vector<char> vc;
		dfs(0, maxn, maxn, vc, -1);
		cout << "Found " << cnt << " golygon(s)." << endl << endl;
	}//while kasenum
	return 0;
}