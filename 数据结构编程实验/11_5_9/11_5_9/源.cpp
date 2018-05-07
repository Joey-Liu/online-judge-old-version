#include <iostream>
using namespace std;

const int maxn = 30;
int map[maxn][maxn];//到达 结点时 的步数
bool visited[maxn][maxn];
bool success = false;

struct
{
	int r,c;
}route[maxn];

int row,col;

int dc[8] = {-1,1,-2,2,-2,2,-1,1};
int dr[8] = {-2,-2,-1,-1,1,1,2,2};

bool in_range(int ro,int co)
{
	if(ro >= 1 && ro <= row && co >= 1 && co <= col)
		return true;
	return false;
}


void dfs(int ro,int co,int step)
{
	if(step==row * col)
	{
		for(int i = 0;i < step;i++)
			cout<<char(route[i].r + 'A' - 1)<<route[i].c;
		cout<<endl<<endl;
		success = true;
		return;
	}

	int tr,tc;
	for(int i = 0;i < 8;i++)
	{
		tr = ro + dr[i];
		tc = co + dc[i];
		if(in_range(tr,tc) && !visited[tr][tc])
		{
			visited[tr][tc] = true;
			//////////////////////////比较重要
			route[step].r = tr;
			route[step].c = tc;
			dfs(tr,tc,step + 1);

			visited[tr][tc] = false;
			if(success)
				break;
		}
	}//for int i
}


int main()
{
	freopen("sin","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	for(int cnt = 1;cnt <= casenum;cnt++)
	{
		cin>>col>>row;
		memset(map,-1,sizeof(map));
		memset(visited,false,sizeof(visited));

		cout<<"Scenario #"<<cnt<<":"<<endl;
		success = false;
		route[0].r = 1;
		route[0].c = 1;
		visited[1][1] = true;
		dfs(1,1,1);

		if(!success)
			cout<<"impossible"<<endl<<endl;

	}//for cnt
	return 0;
}