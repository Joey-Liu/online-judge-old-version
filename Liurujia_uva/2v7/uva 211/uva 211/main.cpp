#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <set>
#include <sstream>
#include <map>

using namespace std;

const int maxn = 10;
int grid[maxn][maxn];
set<int> pips[7];
int cs[maxn], res[maxn][maxn], cnt = 0;

typedef pair<int, int> PII;
map<PII, int> tab;
map<PII, bool> vis;

void init()
{
	int ind = 1;
	for (int i = 0; i <= 6; i++) {
		for (int j = i; j <= 6; j++) {
			PII pi(i, j);
			tab[pi] = ind;
			vis[pi] = false;
			ind++;
		}
	}
}

bool in_mat(int r, int c) {
	if (r < 0 || r >= 7 || c < 0 || c >= 8)
		return false;
	return true;
}
	
void dfs(int pos) {
	if (pos == 56) {
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 8; j++) {
				cout.width(4);
				cout << res[i][j];
			}
			cout << '\n';
		}
		cout << "\n\n";
		cnt++;
	}

	int r = pos / 8, c = pos % 8;
	if (res[r][c] != -1)
	{
		dfs(pos + 1);
		return;
	}

	int nr = r, nc = c + 1;
	if (in_mat(nr, nc) && -1 == res[nr][nc]) {
		int a = grid[r][c], b = grid[nr][nc];
		if (a > b)
			swap(a, b);
		PII pi(a, b);
		if (tab.count(pi) && !vis[pi]) {
			int k = tab[pi];
			res[r][c] = k;
			res[nr][nc] = k;
			vis[pi] = true;
			dfs(pos + 2);
			res[r][c] = -1;
			res[nr][nc] = -1;
			vis[pi] = false;
		}
	}

	nr = r + 1; nc = c;
	if (in_mat(nr, nc) && -1 == res[nr][nc]) {
		int a = grid[r][c], b = grid[nr][nc];
		if (a > b)
			swap(a, b);
		PII pi(a, b);
		if (tab.count(pi) && !vis[pi]) {
			int k = tab[pi];
			res[r][c] = k;
			res[nr][nc] = k;
			vis[pi] = true;
			dfs(pos + 1);
			res[r][c] = -1;
			res[nr][nc] = -1;
			vis[pi] = false;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	string str;
	int kasenum = 0;
	while (getline(cin, str)) {
		stringstream ss(str);
		for (map<PII, bool>::iterator it = vis.begin(); it != vis.end(); it++)
			it->second = false;
		cnt = 0;
		memset(res, -1, sizeof(res));

		for (int i = 0; i < 8; i++)
			ss >> grid[0][i];
		for (int i = 1; i < 7; i++)
			for (int j = 0; j < 8; j++)
				cin >> grid[i][j];
		cin.get();

		if (kasenum)
			cout << "\n\n\n\n";
		cout << "Layout #" << ++kasenum << ":" << "\n\n\n";
		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 8; j++) {
				cout.width(4);
				cout << grid[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "Maps resulting from layout #" << kasenum << " are:" << "\n\n\n";
		dfs(0);
		cout << "There are " << cnt << " solution(s) for layout #" << kasenum << ".\n\n";
	}
	return 0;
}