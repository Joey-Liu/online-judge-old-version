#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>

using namespace std;

const int maxn = 20 + 10;

int tab[maxn][maxn];
bool visited[maxn];
int N, K;
int cut[maxn][maxn];
vector<vector<int> > vvi;

void floyed()
{
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			if (tab[i][j])
				cut[i][j] = cut[j][i] = 1;

	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < maxn; j++)
			for (int k = 0; k < maxn; k++)
				if (cut[i][k] && cut[k][j])
					cut[i][j] = cut[j][i] = 1;
}

void dfs(int n, vector<int> vi)
{
	if (n == K)
	{
		vvi.push_back(vi);
		return;
	}

	for (int i = 1; i < N; i++)
	{
		if (tab[n][i] && cut[i][K] && !visited[i])
		{
			vector<int> t = vi;
			visited[i] = true;
			vi.push_back(i);
			dfs(i, vi);
			visited[i] = false;
			vi = t;
		}
	}
}

void print()
{
	for (int i = 0; i < vvi.size(); i++)
	{
		cout << vvi[i][0];
		for (int j = 1; j < vvi[i].size(); j++)
			cout << " " << vvi[i][j];
		cout << "\n";
	}
	cout << "There are " << vvi.size() << " routes from the "
		"firestation to streetcorner " << K <<"."<< endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	while (cin >> K)
	{
		N = maxn;
		memset(tab, 0, sizeof(tab));
		memset(visited, false, sizeof(visited));
		memset(cut, 0, sizeof(cut));
		vvi.clear();
		
		int a, b;
		while (cin >> a >> b && a && b)
		{
			tab[a][b] = 1;
			tab[b][a] = 1;
		}//while cin
		floyed();

		vector<int> vi = { 1 };
		visited[1] = true;

		dfs(1, vi);
		cout << "CASE " << ++kasenum << ":\n";
		print();
	}//while cin>>fire
	return 0;
}