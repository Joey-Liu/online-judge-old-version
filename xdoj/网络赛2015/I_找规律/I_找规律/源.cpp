#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;
const int maxn = 1000 + 5;

int matrix[maxn][maxn];
vector<int > factor;


void init()		// to init the matrix,the matrix based on 1 (both row and col)
{

	for (int i = 1; i < maxn; i++)
		matrix[i][i] = 2;

	//
	for (int i = 1; i < maxn; i++)
		matrix[1][i] = i + 1;

	//2,4,6.....
	for (int j = 1; j < maxn; j++)
	{
		factor.clear();
		int col = j;
		int row = 1;
		int num = matrix[1][j];
		for (int i = 2; i < num / 2; i++)
		{
			if (num % i == 0)
			{
				factor.push_back(num / i);
			}
		}
		factor.push_back(num);

		int index = 0;
		while (true)
		{
			col--;
			row++;
			if (row >= col)
				break;
			matrix[row][col] = factor[index++];
			index = index % factor.size();
		}//while true
	}

	for (int i = 1; i < maxn; i++)
	{
		for (int j = i + 1; j < maxn; j++)
		{
			matrix[j][i] = matrix[i][j];
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	int n, m, ans = 0;
	while (2 == scanf("%d %d", &n, &m))
	{
		ans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				ans += matrix[i][j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}