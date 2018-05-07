#include <iostream>
#define inf 0x3f3f3f3f

using namespace std;
const int maxn = 300 + 20;
int lx[maxn],ly[maxn];//结点顶标
int pre[maxn];//结点前驱
int slack[maxn];//结点 顶标与边权 最小差值
bool visx[maxn],visy[maxn];
int map[maxn][maxn];
int num;//村民 房子数量

bool dfs(int i)//寻找可行边
{
	visx[i] = true;
	for(int j = 1;j <= num;j++)
	{
		if(visy[j])
			continue;
		
		int t = lx[i] + ly[j] - map[i][j];
		if(0==t)//可行边
		{
			slack[j] = 0;
			visy[j] = true;//放在下面应该也可以
			if(pre[j]==0 || dfs(pre[j]))
			{
				pre[j] = i;
				return true;
			}
		}
		else
			slack[j] = min(slack[j],t);
	}//for int j
	return false;
}

int KM()
{
	memset(pre,0,sizeof(pre));
	memset(ly,0,sizeof(ly));
	memset(lx,0,sizeof(lx));

	for(int i = 1;i <= num;i++)
		for(int j = 1;j <= num;j++)
			if(map[i][j] > lx[i])
				lx[i] = map[i][j];

	for(int x = 1;x <= num;x++)//对每一个x 结点求增广路径增加可行边
	{
		for(int i = 1;i <= num;i++)
			slack[i] = inf;
		while(true)
		{
			memset(visx,false,sizeof(visx));
			memset(visy,false,sizeof(visy));

			if(dfs(x))
				break;

			//否则 求出常数 d ，顶标减d 
			int d = inf;
			for(int i = 1;i <= num;i++)
				if(!visy[i] && d > slack[i])
					d = slack[i];

			for(int i = 1;i <= num;i++)
				if(visx[i])
					lx[i] -= d;

			for(int i = 1;i <= num;i++)
				if(visy[i])//			如果i不在增广路径中 由于 visx[i] 已经减去 d 还要更新 slack值
					ly[i] += d;
				else
					slack[i] -= d;

		}
	}//for int x
	int ans = 0;
	for(int i = 1;i <= num;i++)
		if(pre[i] != 0)
			ans += map[pre[i]][i];

	return ans;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>num)
	{
		for(int i = 1;i <= num;i++)
			for(int j = 1;j <= num;j++)
				cin>>map[i][j];

		cout<<KM()<<endl;
	}
	return 0;
}