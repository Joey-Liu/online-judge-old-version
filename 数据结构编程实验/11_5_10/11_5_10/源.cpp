#include <iostream>
using namespace std;

const int maxn = 40 + 10;
int row,col;
bool map[maxn][maxn];
//bool flag = false;//是否找到出口
int step = 1;
int sr,sc;
int er,ec;

int dr[4] = {0,-1,0,1};
int dc[4] = {-1,0,1,0};
int dis[maxn][maxn];

bool in_range(int ro,int co)
{
	if(ro >= 1 && ro <= row && co >= 1 && co <= col && map[ro][co])
		return true;
	return false;
}


void init()
{
	memset(map,true,sizeof(map));
	memset(dis,100,sizeof(dis));

	char ch;
	cin>>col>>row;
	for(int i = 1;i <= row;i++)
	{
		for(int j = 1;j <= col;j++)
		{
			cin>>ch;
			if('#'==ch)
				map[i][j] = false;
			else if('S'==ch)
			{
				sr = i;
				sc = j;
			}//for int j
			else if('E'==ch)
			{
				er = i;
				ec = j;
			}
		}//for int j
	}
	step = 0;
}


int dfs_left(int ro,int co,int t)//t 为当前位置方向
{
	if(!map[ro][co] || !in_range(ro,co))
		return 2;
	
	bool flag = false;
	step++;
	if(ro==er && co==ec)//到达终点
		return 1;
	
	int tt = (t + 3) % 4;//逆时针旋转90,(向左走)
	for(int i = 0;i < 4;i++)
	{
		int res = dfs_left(ro + dr[tt],co + dc[tt],tt);
		if(1==res)
		{
			flag = true;
			break;
		}
		else if(0==res)//没有找到终点，返回后换个方向
		{
			step++;
			tt = (tt + 1) % 4;
		}
		else
			tt = (tt + 1) % 4;
	}
	return flag;
}


int dfs_right(int ro,int co,int t)//t 为当前位置方向
{
	if(!map[ro][co] || !in_range(ro,co))
		return 2;
	
	bool flag = false;
	step++;
	if(ro==er && co==ec)//到达终点
		return 1;
	
	int tt = (t + 1) % 4;//顺时针旋转90,(向右走)
	for(int i = 0;i < 4;i++)
	{
		int res = dfs_right(ro + dr[tt],co + dc[tt],tt);
		if(1==res)
		{
			flag = true;
			break;
		}
		else if(0==res)//没有找到终点，返回后换个方向
		{
			step++;
			tt = (tt + 3) % 4;
		}
		else
			tt = (tt + 3) % 4;
	}
	return flag;
}


void dfs(int ro,int co,int k)//第k步走到 该节点
{
	if(!in_range(ro,co) || !map[ro][co] || k >= dis[ro][co])//如果是墙 或曾经访问过
		return;

	dis[ro][co] = k;
	if(ro==er && co==ec)
	{
		step = k;
		return;
	}

	for(int i = 0;i < 4;i++)
	{
		dfs(ro + dr[i],co + dc[i],k + 1);
	}
}

int main()
{
	freopen("7.in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		init();
		
		dfs_left(sr,sc,0);
		cout<<step<<" ";
		step = 0;

		dfs_right(sr,sc,0);
		cout<<step<<" ";
		step = 0;
		

		dfs(sr,sc,1);
		cout<<step<<endl;
	}
	return 0;
}