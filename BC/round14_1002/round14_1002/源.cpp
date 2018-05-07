#include <iostream>
using namespace std;

const int maxn = 50 + 10;
int map[maxn][maxn];
int n,m;
int res = 0;//结果时间
int cnt = 0;
int req = 0;//石头数量
bool isFind = false;

bool in_range(int r,int c)
{
	if(r >= 0 && r < n && c >= 0 && c < m)
		return true;
	return false;
}

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};
int trd,tcd;

struct 
{
	int row;
	int col;
}que[maxn * 10];


void init()
{
	memset(map,0,sizeof(map));
	int tmp;
	req = cnt = res = 0;

	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			cin>>tmp;
			if(tmp > 0)
			{	
				map[i][j] = 1;
				req++;
			}
		}
	}

	map[0][0] = -1;
}

void bfs(int ro,int co,int  step)
{
	if(1==map[ro][co])
	{
		cnt++;
		isFind = true;
		map[ro][co] = -1;
		trd = ro;
		tcd = co;
		if(cnt==req)
			cout<<step + ro + co<<endl;
		return;
	}

	for(int i =0;i < 4;i++)
	{
		int tr = ro + dr[i];
		int tc = co + dc[i];
		if(in_range(tr,tc) && -1 != map[tr][tc])
		{
			int tmp = map[tr][tc];
			if(1==map[tr][tc])
			{
				cnt++;
				isFind = true;
				map[ro][co] = -1;
				trd = ro;
				tcd = co;
				if(cnt==req)
					cout<<step + ro + co<<endl;
				return;
			}

			map[tr][tc] = -1;

			bfs(tr,tc,step + 1);
			if(tmp==1)
				map[tr][tc] = -1;
			else
				map[tr][tc] = 0;

			if(isFind)
				break;
		}
	}
}

void bfs()
{
	int lp = 0;
	int rp = 1;
	que[lp].row = 0;
	que[lp].col = 0;

	while(cnt < req)
	{
			

	}//while
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>n>>m)
	{
		init();
		cnt = 0;
		map[0][0] = -1;
		trd = 0,tcd = 0;

		while(cnt < req)
		{
			bfs(trd,tcd,0);
			isFind = false;
		}
	}
	return 0;
}