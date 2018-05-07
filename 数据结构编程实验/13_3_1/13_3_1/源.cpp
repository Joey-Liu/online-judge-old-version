#include <iostream>
using namespace std;

const int maxn_node = 270;
const int maxn_cost = (INT_MAX / 8);

typedef struct 
{
	int nextop;
	int cost;
}t_route;

t_route route[maxn_node][maxn_node];
int cost[maxn_node][maxn_node];//花费矩阵,对角线为税费
int city;

int read()
{
	cin>>city;
	if(0==city)
		return 0;

	for(int i = 1; i<= city;i++)
		for(int j = 1;j <= city;j++)
			cin>>cost[i][j];

	for(int i = 1;i <= city;i++)
		cin>>cost[i][i];
	return 1;
}

void init_route()
{
	//初始化最少费用矩阵
	for(int i = city;i--;)
	{
		for(int j = city;j--;)
		{
			if(i==j)
			{
				route[i][j].cost = 0;
				route[i][j].nextop = i;
			}
			if(cost[i][j] > 0)
			{
				route[i][j].cost = cost[i][j];
				route[i][j].nextop = j;
			}
			else
			{
				route[i][j].cost = maxn_cost;
				route[i][j].nextop = -1;
			}
		}
	}//for int i

	//Bellman Ford
	for(int V = city - 1;V--;)
	{
		for(int i = city;i--;)//出发城市
		{
			for(int j = city;j--;)//首个交税城市
			{
				if(i==j || cost[i][j] <= 0)
					continue;
				for(int k = city;k--;)//目的城市
				{
					int tmp = route[j][k].cost + cost[j][j] + cost[i][j];
					int cur = route[i][k].cost;

					if(tmp < cur || tmp==cur && route[i][k].nextop > j)
					{
						route[i][k].cost = tmp;
						route[i][k].nextop = j;
					}

				}
			}
		}//for int i

	}
}

void solve()
{
	int from,to;
	while(true)
	{
		cin>>from>>to;
		if(-1==from)
			return;
		cout<<"from "<<from<<" to "<<to<<" :"<<endl;
		cout<<"Path: "<<from;
		int next,pre;//pre为上各城市
		pre = from;
		if(from != to)
		{
			for(next = route[from][to].nextop;next != to;next = route[next][to].nextop)
			{
				if(next==from)
				{
					cout<<"产生环路！"<<endl;
					break;
				}
				cout<<"-->"<<next;
				pre= next;
			}
			cout<<"-->"<<next<<endl;
		}//if
		else
			cout<<endl;
		cout<<"Total cost : "<<route[from][to].cost<<endl<<endl;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(read())
	{
		init_route();
		solve();
	}
	return 0;
}