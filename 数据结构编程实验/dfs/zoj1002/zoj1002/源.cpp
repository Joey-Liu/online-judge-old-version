#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;
struct node
{
	int r;
	int c;
};

const int maxn = 10;
char map[maxn][maxn];
bool vis[maxn][maxn];		//这个节点是否已经放置过碉堡
node pos[maxn * 2];		//分别记录第1、2、3....个点的位置
int mx = 0;			//可放置的最大数量
int ans = 0;		//最终结果

int breadth;

bool in_range(int row, int col)
{
	if (row < 0 || row >= breadth || col < 0 || col >= breadth)
		return false;
	return true;
}

//bool place(int row,int col)
//{
//	for (int i = 0; i < ans; i++)
//	{
//		if (pos[i].r != row && pos[i].c != col)		//不同行 不同列
//			continue;
//		else if (pos[i].r == row)				
//		{
//			for (int j = pos[i].c + 1; j < col; j++)	//同行
//			{
//				if ('X' == map[row][j])
//					continue;
//			}
//			return false;
//		}//else if
//		else if (pos[i].c == col)		//同列
//		{
//			for (int j = pos[i].r + 1; j < row; j++)
//			{
//				if ('X' == map[j][col])
//					continue;
//			}
//			return false;
//		}//else if
//	}//for int i
//
//	return true;
//}

bool place(int row, int col)
{

}


void DFS()			//一个一个结点DFS ，感觉有点像暴搜了
{
	if (mx > ans)
		ans = mx;

	for (int i = 0; i < breadth; i++)
	{
		for (int j = 0; j < breadth; j++)
		{
			if ('X' == map[i][j])
				continue;
			if (place(i,j) && !vis[i][j])
			{
				vis[i][j] = true;
				mx++;
				DFS();
				vis[i][j] = false;
				mx--;
			}
		}// for intj
	}//for inti
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> breadth;
	while (0 != breadth)
	{
		memset(map, 0, sizeof(map));
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < breadth; i++)
		{
			for (int j = 0; j < breadth; j++)
				cin >> map[i][j];
		}
		mx = 0;
		ans = 0;
		DFS();
		cout << ans << endl;
		cin >> breadth;
	}
}