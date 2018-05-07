#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <math.h>

using namespace std;
const int maxn = 64 + 5;

char graph[maxn][maxn];

int N;
vector<int> res;

int work_a(int rop, int cop, int red, int ced, int layer, int cur)
{
	bool w = true, b = true;
	for (int i = rop; i < red; i++)
	{
		for (int j = cop; j < ced; j++)
		{
			if ('0' == graph[i][j])
				b = false;
			else
				w = false;
		}
	}//for int i
	if (w || b)
	{
		if (layer < 0)
		{
			if (b)
				res.push_back(cur);
		}
		return b ? cur : -1;
	}
	int t, size = red - rop;

	t = work_a(rop, cop, rop + size / 2, cop + size / 2, layer + 1, cur + 1 * pow(5, layer + 1));
	if (-1 != t)
		res.push_back(t);
	t = work_a(rop, cop + size / 2, rop + size / 2, ced, layer + 1, cur + 2 * pow(5, layer + 1));
	if (-1 != t)
		res.push_back(t);
	t = work_a(rop + size / 2, cop, red, cop + size / 2, layer + 1, cur + 3 * pow(5, layer + 1));
	if (-1 != t)
		res.push_back(t);
	t = work_a(rop + size / 2, cop + size / 2, red, ced, layer + 1, cur + 4 * pow(5, layer + 1));
	if (-1 != t)
		res.push_back(t);
	return -1;
}

void draw(int r, int c, int size, queue<int>  &vi)
{
	if (vi.empty())
	{
		for (int i = r; i < r + size; i++)
		{
			for (int j = c; j < c + size; j++)
				graph[i][j] = '1';
		}
		return;
	}

	int t = vi.front();
	vi.pop();
	switch (t)
	{
	case 1:
		draw(r, c, size / 2, vi);
		break;
	case 2:
		draw(r, c + size / 2, size / 2, vi);
		break;
	case 3:
		draw(r + size / 2, c, size / 2, vi);
		break;
	case 4:
		draw(r + size / 2, c + size / 2, size / 2, vi);
		break;
	}
}

void work_b(int num)
{
	queue<int> vi;
	while (num != 0)
	{
		vi.push(num % 5);
		num /= 5;
	}
	draw(0, 0, N, vi);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (cin >> N && N)
	{
		if (N > 0)
		{
			if (kasenum)
				cout << "\n";
			res.clear();
			for (int i = 0; i < N; i++)
				cin >> graph[i];
			work_a(0, 0, N, N, -1, 0);
			sort(res.begin(), res.end());
			cout << "Image " << ++kasenum << endl;
			for (int i = 0; i < res.size(); i++)
			{
				cout << res[i];
				if (i == res.size() - 1 || (i && 11 == i % 12))
					cout << "\n";
				else
					cout << ' ';
			}
			cout << "Total number of black nodes = " << res.size() << "\n";
		}
		else
		{
			if (kasenum)
				cout << "\n";
			N = -N;
			memset(graph, '0', sizeof(graph));
			int t;
			while (cin >> t && -1 != t)
				work_b(t);
			cout << "Image " << ++kasenum << endl;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if ('1' == graph[i][j])
						cout << "*";
					else
						cout << ".";
				}
				cout << "\n";
			}
		}
	}//while
	return 0;
}