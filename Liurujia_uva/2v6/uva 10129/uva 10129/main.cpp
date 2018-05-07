#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <set>

using namespace std;

map<char, int> rudu;
map<char, int> chudu;
const int maxn = 30;
int graph[maxn][maxn];
bool visited[maxn];

set<int> vob;

void dfs(int c)
{
	visited[c] = true;
	for (int i = 0; i < maxn; i++)
	{
		if (i == c)
			continue;
		if (vob.count(i) && graph[c][i] && !visited[i])
			dfs(i);
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		rudu.clear();
		chudu.clear();
		vob.clear()
			;
		string word;
		memset(graph, 0, sizeof(graph));
		memset(visited, false, sizeof(visited));

		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cin >> word;
			char bw = word[0], ew = word[word.size() - 1];
			if (!chudu.count(bw))
				chudu[bw] = 0;
			if (!chudu.count(ew))
				chudu[ew] = 0;

			if (!rudu.count(bw))
				rudu[bw] = 0;
			if (!rudu.count(ew))
				rudu[ew] = 0;

			chudu[bw]++;
			rudu[ew]++;
			
			int bi = bw - 'a', ei = ew - 'a';
			graph[bi][ei] = 1;
			graph[ei][bi] = 1;
			vob.insert(bi);
			vob.insert(ei);
		}

		dfs(word[0] - 'a');
		bool liantong = true;
		for (set<int>::iterator it = vob.begin(); it != vob.end(); it++)
		{
			if (!visited[*it])
			{
				liantong = false;
				break;
			}
		}

		bool ans = false;
		int a = 0, b = 0;
		if (rudu.size() != chudu.size())
			ans = false;
		else
		{
			for (map<char, int>::iterator it = chudu.begin(); it != chudu.end(); it++)
			{
				char c = it->first;
				int t = chudu[c] - rudu[c];
				if (!t)
					continue;
				else if (1 == t)
					a++;
				else if (-1 == t)
					b++;
				else
				{
					a = 100;
					break;
				}
			}
			if (liantong && ((a == 1 && 1 == b) || (!a && !b)))
				ans = true;
		}
		if (ans)
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;
	}
	return 0;
}