#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <queue>

using namespace std;

const int maxn = 500 + 20;

int N, M, K;
string timetable[maxn];

struct Node
{
	int r, c;
	bool first;
	bool last;
	int get_time;
};

int visited[maxn][maxn];

struct cmp {
	bool operator() (const Node &a, const Node &b)
	{
		if (a.get_time < b.get_time)
			return true;
		return false;
	}
};

Node mmmp[maxn][maxn];
priority_queue<Node, cmp> que;

int get_continue_zero(int r, int c)
{
	int k = c + 1, res = 0;
	while (k < M && timetable[r][k] == '0')
	{
		k++;
		res++;
	}
	return res;
}

void work()
{
	for (int i = 0; i < N; i++)
	{
		int cur = get_continue_zero(i, -1);
		if (cur == M)
			continue;
		
		mmmp[i][cur].first = true;
		mmmp[i][cur].get_time = cur;
		visited[i][cur] = true;
		int prev = cur, tmp = cur;
		bool first = true;
		while (cur < M)
		{
			int czn = get_continue_zero(i, cur);
			mmmp[i][cur].get_time += (czn + 1);
			if (first)
				que.push(mmmp[i][cur]);
			prev = cur;
			cur += (czn + 1);
		}
		if(cur == )

	}
}

int main()
{
	while (cin >> N >> M >> K)
	{
		for (int i = 0; i < N; i++)
			cin >> timetable[i];
		
		for (int i = 0; i < N; i++)
		{
			int ind = 0;
			while (timetable[i][ind] == '0')
				ind++;
			if (ind < M)
			{
				Node node;
				node.first = true;
				node.get_time = 1 + ind;
				ind += 1;
				int ind_2 = 0;
				while (ind < M && timetable[i][ind] == '0')
					ind_2++;
				node.get_time += ind_2;
				if (ind == M)
					node.last = true;
				que.push(node);
			}

			ind = M - 1;
			while (timetable[i][ind] == '0')
				ind--;
			if (ind >= 0)
			{

			}
		}//for int i
	}
	return 0;
}