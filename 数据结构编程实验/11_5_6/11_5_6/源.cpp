#include <iostream>
using namespace std;

const int maxn = 15;//将地图扩展
struct {
	int row;
	int col;
	int pre;//父指针
	int dir;//方向
}thend,que[50];

bool map[maxn][maxn];//墙为true，访问过为true
bool hasfind;//
int lp,rp;//队列首尾指针

char trans(int w)
{
	if(0==w) return 'N';
	if(1==w) return 'W';
	if(2==w) return 'E';
	if(3==w) return 'S';
}

int dr[4] = {-2,0,0,2};
int dc[4] = {0,-2,2,0};//相应的为 北西东南

bool in_range(int r,int c)//判断是否超出地图
{
	if(r >= 0 && r <= 12 && c >= 0 && c <= 12)
		return true;
	return false;
}

bool crosswall(int r,int c,int w)//判断是否穿过墙
{
	if(0==w) return map[r + 1][c];
	if(1==w) return map[r][c + 1];
	if(2==w) return map[r][c - 1];
	if(3==w) return map[r - 1][c];
}


void init(int sr,int sc)
{
	memset(map,false,sizeof(map));
	//边界上围墙
	for(int i = 0;i <= 12;i++)
		map[0][i] = true;
	for(int i = 0;i <= 12;i++)
		map[i][0] = true;
	for(int i = 0;i <= 12;i++)
		map[i][12] = true;
	for(int i = 0;i <= 12;i++)
		map[12][i] = true;

	sr = sr * 2 - 1;
	sc = sc * 2 - 1;

	cin>>thend.col>>thend.row;
	thend.row = thend.row * 2 -1;
	thend.col = thend.col * 2 -1;

	int tr,tc,wr,wc;
	for(int i = 0;i < 3;i++)
	{
		cin>>tc>>tr>>wc>>wr;
		tr *= 2;
		tc *= 2;
		wr *= 2;
		wc *= 2;

		if(tc==wc)//水平方向 造墙
		{
			for(int st = tr;st <= wr;st++)
				map[st][tc] = true;
		}
		else
		{
			for(int st = tc;st <= wc;st++)
				map[tr][st] = true;
		}
	}//for int
	que[0].row = sr;
	que[0].col = sc;
	que[0].pre  = 0;//没有前驱
	que[0].dir = -1;

	hasfind = false;
	lp = 0,rp = 1;
}//init


void bfs()
{
	int tr,tc;
	lp = 0;
	rp = 1;
	map[que[lp].row][que[lp].col ] = true;
	while(!hasfind)
	{
		//依次添加 四个儿子结点
		for(int i = 0;i < 4;i++)
		{
			tr = que[lp].row + dr[i];
			tc = que[lp].col + dc[i];
			if(in_range(tr,tc) && !crosswall(tr,tc,i) && !map[tr][tc])
			{
				map[tr][tc] = true;//结点已访问过
				que[rp].row = tr;
				que[rp].col = tc;
				que[rp].pre = lp;
				que[rp].dir = i;
				if(tr==thend.row && tc==thend.col)
				{
					hasfind = true;
					break;
				}
				rp++;
			}
		}
		lp++;
	}//while !find
}

void print(int k)
{
	if(0==k)
		return;
	else
	{
		print(que[k].pre);
		cout<<trans(que[k].dir);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int sr,sc;
	cin>>sc>>sr;
	while(sr || sc)
	{
		init(sr,sc);
		bfs();
		print(rp);
		cout<<endl;
		cin>>sc>>sr;
	}
}