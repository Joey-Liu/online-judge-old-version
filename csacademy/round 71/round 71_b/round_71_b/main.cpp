#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;

const int maxn = 500 + 10;
int matrix[maxn][maxn], res_matrix[maxn][maxn];
pair<int, int> de_matrix[maxn][maxn];

int dr[] = { -1, -1, 0, 1, 1, 1 ,0, -1 };
int dc[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int N, M;

bool in_matrix(int r, int c)
{
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

pair<int, int> move(int r, int c)
{
	if (de_matrix[r][c].first >= 0)
	{
		res_matrix[de_matrix[r][c].first][de_matrix[r][c].second]++;
		return de_matrix[r][c];
	}

	int cv = matrix[r][c];
	int mini = cv;
	int lr = -1, lc = -1;
	for (int i = 0; i < 8; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!in_matrix(nr, nc))
			continue;
		if (matrix[nr][nc] < mini)
		{
			lr = nr;
			lc = nc;
			mini = matrix[nr][nc];
		}
	}
	if (lr >= 0)
	{
		res_matrix[r][c]--;
		pair<int, int> pa;
		pa = move(lr, lc);
		de_matrix[r][c] = pa;
	}
	else
	{
		pair<int, int> pa(r, c);
		de_matrix[r][c] = pa;
	}
	return de_matrix[r][c];
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%d%d", &N, &M))
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				scanf("%d", &matrix[i][j]);

		memset(res_matrix, 0, sizeof(res_matrix));
		memset(de_matrix, -1, sizeof(de_matrix));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				move(i, j);
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (j)
					printf(" ");
				printf("%d", res_matrix[i][j] + 1);
			}
			printf("\n");
		}
	}//while cin
	return 0;
}