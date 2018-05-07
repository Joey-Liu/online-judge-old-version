#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
using namespace std;

const int maxn = 100 + 5;
bool grid[maxn][maxn];
int row,col,res;

int dr[8] = {-1,0,1,0,-1,1,1,-1};
int dc[8] = {0,1,0,-1,1,1,-1,-1};

void init()
{
	res = 0;
	char ch;
	memset(grid,false,sizeof(grid));
	for(int i = 0;i < row;i++)
		for(int j = 0; j < col;j++)
		{
			cin>>ch;
			if('@'==ch)
				grid[i][j] = true;
		}
}

bool in_range(int r,int c)
{
	if(r >= 0 && r < row && c >= 0 && c < col)
		return true;
	return false;
}

void dfs(int r,int c)
{
	int tr,tc;
	for(int i = 0;i < 8;i++)
	{
		tr = r + dr[i];
		tc = c + dc[i];
		if(in_range(tr,tc) && grid[tr][tc])
		{
			grid[tr][tc] = false;
			dfs(tr,tc);
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(cin>>row>>col && row != 0)
	{
		init();
		for(int i = 0;i < row;i++)
		{
			for(int j = 0;j < col;j++)
			{
				if(grid[i][j])
				{
					grid[i][j] = false;
					dfs(i,j);
					res++;
				}
			}
		}//for int i
		cout<<res<<endl;
	}//while
	return 0;
}