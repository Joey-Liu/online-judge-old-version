#include <iostream>
#include <memory.h>
#include <limits.h>
using namespace std;

const int maxn = 100 + 10;
int map[maxn][maxn];
int mytime;

void init(int num)
{
	memset(map,-1,sizeof(map));
	mytime = INT_MAX;
	for(int i = 1;i <= num;i++)
	{
		int peop_num;
		cin>>peop_num;
		int peop_sign,mins;
		for(int j = 1;j <= peop_num;j++)
		{
			cin>>peop_sign>>mins;
			map[i][peop_sign] = mins;
		}
	}//int i
}


void solve(int num)
{
	for(int k = 1;k <= num;k++)
		for(int i = 1;i <= num;i++)
			for(int j = 1;j <= num;j++)
				if(i != j && i != k && j != k)
					if(map[i][k] + map[k][j] < map[i][j] && map[i][k] > 0 && map[k][j] > 0)
						map[i][j] = map[i][k] + map[k][j];
					else if(-1==map[i][j] && map[i][k] > 0 && map[k][j] > 0)
						map[i][j] = map[i][k] + map[k][j];
	int sign = 0,tmp = 0;
	for(int i =1;i <= num;i++)
	{
		bool flag = true;
		tmp = 0;
		for(int j = 1;j <= num;j++)
		{
			if(-1==map[i][j] && i != j)
				flag = false;
			if(tmp < map[i][j])
				tmp = map[i][j];
		}
		if(tmp < mytime && tmp > 0 && flag)
		{
			mytime  = tmp;
			sign = i;
		}
	}//for
	if(0==sign)
		cout<<"disjoint"<<endl;
	else
		cout<<sign<<" "<<mytime<<endl;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	cin>>num;
	while(num > 0)
	{
		init(num);
		solve(num);
		cin>>num;
	}
	return 0;
}