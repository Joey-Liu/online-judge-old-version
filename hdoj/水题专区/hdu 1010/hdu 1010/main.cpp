#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char map[9][9];//输入的迷宫矩阵
int dir[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };//4个方向
int OK = 0;
int N, M, T, si, sj, di, dj;
int dfs(int si, int sj, int cnt)
{
	if (si <= 0 || sj <= 0 || si > N || sj > M)//超出边界就说明这条路已经死了，则返回
	{
		return 0;
	}
	if (si == di && sj == dj && cnt == T)//找到终点就返回，把标志位置为1
	{
		OK = 1;
	}
	if (OK)
	{
		return 1;
	}
	int temp = T - cnt - abs(di - si) - abs(dj - sj);//这里就是剪枝，开始没写这里，Time Limit Exceeded了十几次...下面细谈
	if (temp < 0 || temp & 1)
	{
		return 0;
	}
	for (int i = 0; i < 4; ++i)//对走到的每个结点都进行四个方向的探索
	{
		if (map[si + dir[i][0]][sj + dir[i][1]] != 'X')
		{
			map[si + dir[i][0]][sj + dir[i][1]] = 'X';//走过的路不能走，就先置为墙
			dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
			//map[si + dir[i][0]][sj + dir[i][1]] = '.';//探索下一条路时，这个结点要恢复成可以走的状态
		}
	}
	return 0;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N >> M >> T)
	{
		int wall = 0;
		OK = 0;
		if (N == 0 && M == 0 && T == 0)
		{
			break;
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> map[i][j];//这里开始还写的scanf("%c", &map[i][j]);蠢的不谈了...  不过可以这样在for(i)的循环里面写 scanf("%s", &map[i]);
				if (map[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				else if (map[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
				else if (map[i][j] == 'X')
				{
					wall++;
				}
			}
		}
		if (N * M - wall <= T)//一个小剪枝
		{
			cout << "NO" << endl;
			continue;
		}
		map[si][sj] = 'X';
		dfs(si, sj, 0);
		if (OK)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}