#include <iostream>
using namespace std;

const int maxn = 20 + 5;
int map[maxn][maxn];
int height,width;
int er,ec;
int sr,sc;
bool flag = false;
struct node
{
	int row;
	int col;
};
int res = 100;

node mkdir(int ro,int co,int t)
{
	int i,j; node pos;	
	if(0==t)
	{
		for(i = ro;i >= 0;i--)
		{
			if(co==ec && i==er)
				flag = true;
			if(1==map[i][co])
				break;
		}//for int i
		if(i < 0)//会超出棋盘
		{
			pos.col = -1;
			pos.row = -1;
		}
		else
		{
			pos.row = i + 1;
			pos.col = co;
			//障碍消失
			map[i][co] = 0;
		}
		return pos;
	}//0==t
	else if(1==t)
	{
		for(j = co;j < width;j++)
		{
			if(j==ec && ro==er)
				flag = true;
			if(1==map[ro][j])
				break;
		}
		if(j==width)
		{
			pos.col = pos.row =  -1;
		}
		else
		{
			pos.row = ro;
			pos.col = j - 1;
			map[ro][j] = 0;
		}
		return pos;
	}//else if 1==t
	else if(2==t)
	{
		for(i = ro;i < height;i++)
		{
			if(i==er && co==ec)
				flag = true;
			if(1==map[i][co])
				break;
		}
		if(i==height)
		{
			pos.row = pos.col = -1;
		}
		else
		{
			pos.row = i - 1;
			pos.col = co;
			map[i][co] = 0;
		}
		return pos;
	}//else if 2 = t
	else
	{
		for(j = co;j >= 0;j--)
		{
			if(j==ec && ro==er)
				flag = true;
			if(1==map[ro][j])
				break;
		}
		if(j < 0)
		{
			pos.col = pos.row = -1;
		}
		else
		{
			pos.row = ro;
			pos.col = j + 1;
			map[ro][j] = 0;
		}
		return pos;
	}//else
}

void dfs(int ro,int co,int k)//第k步走到
{
	if(k > 10 || k >= res)
		return;
	if(ro==er && co==ec)
	{
		res = min(res,k);
		flag = false;
		return;
	}

	node loc;
	for(int i = 0;i < 4;i++)
	{
		if(i==0 && ro - 1 >= 0 && map[ro - 1][co] != 1)
			loc = mkdir(ro,co,i);
		else if(i==1 && co + 1 < width && map[ro][co + 1] != 1)
			loc = mkdir(ro,co,i);
		else if(i==2 && ro + 1 < height && map[ro + 1][co] !=1 )
			loc = mkdir(ro,co,i);
		else if(i==3 && co - 1 >= 0 && map[ro][co - 1] !=1 )
			loc = mkdir(ro,co,i);
		else
			continue;

		if(flag)
		{
			res = min(k + 1,res);
			flag = false;
			//return;
		}
		if(loc.row != -1 || loc.col != -1)
		{	
			dfs(loc.row,loc.col,k + 1);
			//恢复消除的障碍
			if(0==i)
				map[loc.row - 1][loc.col] = 1;
			else if(1==i)
				map[loc.row][loc.col + 1] = 1;
			else if(2==i)
				map[loc.row + 1][loc.col] = 1;
			else
				map[loc.row][loc.col - 1] = 1;
		}
	}
}

int main()
{
	freopen("D1.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>width>>height;
	while(width || height)
	{
		res = 100;
		flag = false;
		for(int i = 0;i < height;i++)
			for(int j = 0;j < width;j++)
			{
				cin>>map[i][j];
				if(2==map[i][j])
				{
					sr = i;
					sc = j;
				}
				else if(3==map[i][j])
				{
					er = i;
					ec = j;
				}
			}//for int j
		
		dfs(sr,sc,0);
		if(res <= 10)
			cout<<res<<endl;
		else
			cout<<"-1"<<endl;

		cin>>width>>height;
		
		//node loc = mkdir(0,3,2);
	}//while
	return 0;
}