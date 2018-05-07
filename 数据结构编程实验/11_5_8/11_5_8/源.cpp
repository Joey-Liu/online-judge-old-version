#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 30 + 5;
int map[maxn][maxn][maxn];
int dis[maxn][maxn][maxn];//dis[i][j][k] 起点至结点的 最短距离

int minutes = 0;
int layer,row,col;
int sx,sy,sz;
int ex,ey,ez;

int dr[6] = {0,0,1,-1,0,0};
int dc[6] = {1,-1,0,0,0,0};
int dv[6] = {0,0,0,0,-1,1};

void init()
{
	memset(map,false,sizeof(map));
	memset(dis,100,sizeof(dis));

	char ch;
	for(int i = 0;i < layer;i++)
		for(int j = 0;j < row;j++)
			for(int k = 0;k < col;k++)
			{
				cin>>ch;
				if('S'==ch)
				{
					sz = i;
					sx = k;
					sy = j;
					map[i][j][k] = true;
				}
				else if('.'==ch)
					map[i][j][k] = true;
				else if('E'==ch)
				{
					ez = i;
					ex = k;
					ey = j;
					map[i][j][k] = true;
				}
			}
}

bool in_range(int ro,int co,int la)
{
	if(ro >= 0 && ro < row && co >= 0 && co < col && la >= 0 && la < layer)
		return true;
	return false;
}

void bfs(int ro,int co,int la,int cur)//cur 为目前到该节点的时间
{
	dis[la][ro][co] = cur;
	if(la==ez && ro==ey && co==ex)
		return;
	
	if(abs(ro - ey) + abs(co -ex) + abs(la -ez) >= 500 )
		return;//根据 题解 说这是一条重要剪枝

	int tr,tc,tl;
	for(int i = 0;i < 6;i++)//bfs
	{
		tr = ro + dr[i];
		tc = co + dc[i];
		tl = la + dv[i];

		if(in_range(tr,tc,tl) && cur + 1 < dis[tl][tr][tc] && map[tl][tr][tc])
			bfs(tr,tc,tl,cur + 1);
	}
}

int main()
{
	freopen("dungeon.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>layer>>row>>col;
	while(layer || row || col)
	{
		init();
		bfs(sy,sx,sz,0);
		if(dis[ez][ey][ex] > 1600000000)
			cout<<"Trapped!"<<endl;
		else
			cout<<"Escaped in "<<dis[ez][ey][ex]<<" minute(s)."<<endl;
		cin>>layer>>row>>col;
	}
	return 0;
}