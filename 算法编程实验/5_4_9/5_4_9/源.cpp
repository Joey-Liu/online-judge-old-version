#include <iostream>
using namespace std;

const int maxn = 30;

int fi[maxn];//每个湖开始能钓多少鱼
int	redu[maxn];//每个湖减少鱼数
int onway[maxn];//路程耗费时间
int finum[maxn];//每个湖当前能钓多少鱼
int fitime[maxn];//每个湖停留时间

int restime[maxn];//结果每个湖停留时间,基于1
int ans = 0;//结果鱼的数量

int time = 0;//钓鱼时间 (分钟)
int lakenum = 0;//湖数量

int pickmax(int arr[],int num)
{
	int tmp = 0,record = 1;//如果找不出最大值，那就在1 号湖
	for(int i = 1;i <= num;i++)
	{
		if(arr[i] > tmp)
		{
			record = i;
			tmp = arr[i];
		}
	}
	return record;
}

void init()
{
	cin>>time;
	time *= 60;
	for(int i = 1;i <= lakenum;i++)
		cin>>fi[i];
	for(int i = 1;i <= lakenum;i++)
		cin>>redu[i];

	for(int i = 1;i < lakenum;i++)
		cin>>onway[i];
}


void solve()
{
	int now = 0;//钓鱼总数量
	ans = -1;
	int ed = 1;//枚举每次钓鱼最终湖 的标号
	for(ed = 1; ed <= lakenum;ed++)
	{
		now = 0;
		//初始化,当前钓鱼数量 湖停留时间,钓鱼总时间
		for(int i = 1;i <= lakenum;i++)
		{
			finum[i] = fi[i];
			fitime[i] = 0;
		}
		int sum = time;
		for(int i =1;i < ed;i++)
			sum -= onway[i] * 5;

		while(sum > 0)
		{
			int tmp = pickmax(finum,ed);
			sum -= 5;
			now += finum[tmp];

			fitime[tmp] += 5;//当前湖钓鱼时间
			finum[tmp] = (finum[tmp] - redu[tmp]) > 0 ? finum[tmp] - redu[tmp] : 0;//剩下钓鱼数量
		}//while sum
		
		if(now > ans)
		{
			ans = now;
			for(int i = 1;i <= lakenum;i++)
				restime[i] = fitime[i];
		}
	}//for ed
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>lakenum && lakenum != 0)
	{
		init();
		solve();
		for(int i = 1;i < lakenum;i++)
			cout<<restime[i]<<", ";
		cout<<restime[lakenum]<<endl;
		cout<<"Number of fish expected: "<<ans<<endl<<endl;
	}
}