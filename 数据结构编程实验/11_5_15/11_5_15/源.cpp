//tle
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 1000 + 10;

int map[maxn][maxn];
bool visited[maxn];
int flag = false;
int num;
int ques;

void bfs(int x,int y)//¥”x bfs —∞’“yΩ·µ„
{
	if(x==y)
	{
		flag = true;
		return;
	}

	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(x);
	visited[x] = true;

	while(!q.empty())
	{
		int tmp = q.front();
		q.pop();

		for(int i = 0;i <= num;i++)
		{
			if(map[tmp][i] && !visited[i])
			{
				if(i==y)
				{
					flag = true;
					break;
				}
				q.push(i);
				visited[i] = true;
			}
		}
	}//while
}


void solve(char ch,int m,int n)
{
	if('I'==ch)
	{
		map[m][n] = 1;
		map[n][m] = 1;
	}
	else if('D'==ch)
	{
		map[m][n] = 0;
		map[n][m] = 0;
	}
	else 
	{
		bfs(m,n);
		if(flag)
			cout<<'Y'<<endl;
		else
			cout<<'N'<<endl;
		flag = false;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(map,0,sizeof(map));
	char ch;
	int m,n;
	cin>>num>>ques;
	while(ques--)
	{
		cin>>ch>>m>>n;
		solve(ch,m,n);
	}
	return 0;
}