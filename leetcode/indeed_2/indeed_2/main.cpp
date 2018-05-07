#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <memory>
#include <map>
#include <queue>
#include <set>

using namespace std;

int N, K, M;
const int maxn = 8 + 10;
int me_map[maxn][maxn];
bool dfs_visited_one[maxn];
bool dfs_visited_two[maxn];
int enumerate_one[maxn];
int enumerate_two[maxn];
set<int> ingradient_one;
set<int> ingradient_two;
int global_res = -1;

void calc_eff(int layer);
void work(int layer)
{
	if (layer >= K)
	{
		calc_eff(0);
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (!dfs_visited_one[i])
			{
				enumerate_one[layer] = i;
				dfs_visited_one[i] = true;
				ingradient_one.insert(i);/////
				work(layer + 1);
				dfs_visited_one[i] = false;
				ingradient_one.erase(i);/////
			}
		}
	}
}

void calc_eff(int layer)
{
	if (layer >= K)
	{
		int res = 0;
		for (int i = 0; i < K; i++)
			for (int j = i + 1; j < K; j++)
				res += me_map[enumerate_one[i]][enumerate_one[j]];

		for (int i = 0; i < K; i++)
		{
			if (ingradient_one.end() != ingradient_one.find(enumerate_two[i]))
				continue;

			for (int j = i + 1; j < K; j++)
			{
				if (ingradient_one.end() != ingradient_one.find(enumerate_two[j]))
					continue;
				
				res += me_map[enumerate_two[i]][enumerate_two[j]];
				//printf("%d\n", res);
			}
		}
		if (res > global_res)
			global_res = res;
	}
	else 
	{
		for (int i = 1; i <= N; i++)
		{
			if (!dfs_visited_two[i])
			{
				enumerate_two[layer] = i;
				dfs_visited_two[i] = true;
				ingradient_two.insert(i);/////
				calc_eff(layer + 1);
				dfs_visited_two[i] = false;
				ingradient_two.erase(i);/////
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N >> K >> M;
	int a, b, mu;
	memset(me_map, 0, sizeof(me_map));
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b>>mu;
		me_map[a][b] = mu;
		me_map[b][a] = mu;
	}

	work(0);
	cout << global_res;
	
}