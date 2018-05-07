#include <iostream>
#include <memory.h>
using namespace std;

const int maxn = 20 + 5;
bool room[maxn][maxn];
int row,col,res = 0;

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int sr,sc;

bool in_range(int r,int c)
{
	if(r >= 0 && r < row && c >= 0 && c < col)
		return true;
	return false;
}

void init()
{
	memset(room,false,sizeof(room));
	res = 0;
	char ch;
	for(int i = 0;i < row;i++)
		for(int j = 0;j < col;j++)
		{
			cin>>ch;
			if('.'==ch)
				room[i][j] = true;
			else if('@'==ch)
			{
				sr = i;
				sc = j;
				room[i][j] = true;
			}
		}
}

void DFS(int ro,int co)
{
	res++;
	room[ro][co] = false;
	for(int i = 0; i < 4;i++)
	{
		if(in_range(ro + dr[i],co + dc[i]) && room[ro + dr[i]][co + dc[i]])
			DFS(ro + dr[i],co + dc[i]);
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	cin>>col>>row;
	while(col || row)
	{
		init();
		DFS(sr,sc);
		cout<<res<<endl;
		cin>>col>>row;
	}
	return 0;
}