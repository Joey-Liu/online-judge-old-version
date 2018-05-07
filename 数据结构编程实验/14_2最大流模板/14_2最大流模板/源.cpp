#include <iostream>
using namespace std;

const int maxn = 50;
int map[maxn][maxn];
bool visited[maxn];
int CF[maxn][maxn];//残存网络
int F[maxn][maxn];//流网络
int goal;//汇点
int res;//最大流

int bfs()//寻找增广路径 -1表示未找到 否则返回残存容量
{
	bool hasfind = false;
	int pre[maxn];
	int queue[maxn * 2];
	memset(pre,-1,sizeof(pre));
	memset(visited,false,sizeof(visited));
	int lp,rp;

	queue[0] = 0;
	lp = 0,rp = 1;
	visited[0] = true;
	pre[0] = -1;
	int minc = 16000000;//残存容量

	while(!hasfind && lp != rp)
	{
		int tmp = queue[lp++];
		for(int i = 0;i < maxn;i++)
		{
			if(CF[tmp][i] > 0 && !visited[i])
			{
				visited[i] = true;
				queue[rp++] = i;
				pre[i] = tmp;

				if(i==goal)
				{
					hasfind = true;
					break;
				}
			}
		}
	}//while

	if(!hasfind)
		return -1;
	else
	{
		int tmp = goal;
		while(pre[tmp] != -1)
		{
			minc = min(minc,CF[pre[tmp]][tmp]);
			tmp = pre[tmp];
		}
	
		//对流网络进行更新
		//int tmp = goal;
		tmp = goal;
		while(pre[tmp] != -1)
		{
			if(map[pre[tmp] ][tmp] > 0)
				F[pre[tmp] ][tmp] += minc;
			else
				F[tmp][pre[tmp] ] -= minc;

			tmp = pre[tmp];
		}
		return minc;
	}
}

void updatecf()
{
	for(int i = 0;i < maxn;i++)
		for(int j = 0;j < maxn;j++)
		{
			if(map[i][j] > 0)
				CF[i][j] = map[i][j] - F[i][j];
			else if(map[j][i] > 0)
				CF[i][j] = F[j][i];
			else
				CF[i][j] = 0;
		}//for int j
}

int Ford()
{
	memset(F,0,sizeof(F));
	int tmp = bfs();
	while(-1 != tmp)//对流网络的更新 放在 bfs中
	{
		res += tmp;
		updatecf();
		tmp = bfs();
	}

	return res;
}

void init(int num)//边数
{
	memset(map,0,sizeof(map));
	int a,b,c;
	for(int i = 0;i < num;i++)
	{
		cin>>a>>b>>c;
		map[a][b] = c;
	}
	updatecf();
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	cin>>num;
	goal = 5;
	init(num);
	cout<<Ford()<<endl;
	return 0;

}