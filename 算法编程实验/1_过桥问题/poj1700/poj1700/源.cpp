/*
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
int cost[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int casenum,num;
	cin>>casenum;
	while(casenum--)
	{
		int res = 0;
		cin>>num;
		for(int i = 0;i < num;i++)
			cin>>cost[i];
		sort(cost,cost + num);
		
		while(num > 3)
		{
			if(cost[0] + cost[num - 2] < 2 * cost[1])//只用最快的 人传递手电筒
				res += cost[num - 1] + cost[0] + cost[num - 2] + cost[0];
			else//最快和次快的人传手电筒
				res += cost[1] + cost[0] + cost[num - 1] + cost[1];
			num -= 2;
		}

		if(1==num || 2==num)
			res += cost[num - 1];
		else if(3==num)
			res += cost[0] + cost[1] + cost[2];
		cout<<res<<endl;
	}//while
	return 0;
}
*/
//在discuss中看到的，使用dp试一试
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;

int cost[maxn];
int dp[maxn];//dp[i]//表示经过排序后 前i个人过河的最短时间

int One(int i)//让最快的人 接送
{
	return cost[i] + cost[1];
}

int Two(int i)//让最快的前两个人 接送(包含前一个人)
{
	return 2 * cost[2] + cost[1] + max(cost[i - 1],cost[i]);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum,num;
	cin>>casenum;
	while(casenum--)
	{
		cin>>num;
		for(int i = 1;i <= num;i++)
			cin>>cost[i];
		sort(cost + 1,cost + num + 1);
		
		dp[1] = cost[1];
		dp[2] = cost[2];
		dp[3] = cost[1] + cost[2] + cost[3];

		int index = 4;
		while(index <= num)
		{
			dp[index] = min(dp[index - 1] + One(index),dp[index - 2] + Two(index));
			index++;
		}
		cout<<dp[num]<<endl;
	}
	return 0;
}