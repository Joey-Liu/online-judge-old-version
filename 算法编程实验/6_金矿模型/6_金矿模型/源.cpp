#include <iostream>
using namespace std;

const int max_n = 100;//金矿数量
const int max_people = 10000;

int n;//金矿数量
int peopletotal;//人数
int peopleNeed[max_n];//挖每座金矿所用人数
int gold[max_n];//每座金矿能挖出的金子数量
int dp[max_people][max_n];//dp[i][j]保存了用i个人挖前j个金矿时能够获得的最大金子数量
//等于-1时表示未知

void init()
{
	cin>>peopletotal>>n;
	for(int i = 0;i < n;i++)
		cin>>peopleNeed[i]>>gold[i];

	for(int i = 0;i <= peopletotal;i++)
		for(int j = 0;j < n;j++)
			dp[i][j] = -1;
}

//计算有people个人和前minenum座金矿时能够得到的最大金子数量
int GetMaxGold(int people,int minenum)
{
	int retMaxGold;//返回最大的金子数量

	if(dp[people][minenum] != -1)//说明之前计算过
		return dp[people][minenum];
	else if(0==minenum)//如果只是最后一个金矿时，到达边界
	{
		if(people >= peopleNeed[minenum])//可以开发
		{
			retMaxGold = gold[minenum];
		}
		else
			retMaxGold = 0;
	}
	else if(people >= peopleNeed[minenum])//可以开采目前这座金矿
	{
		retMaxGold = max( gold[minenum] + GetMaxGold(people - peopleNeed[minenum],minenum - 1),GetMaxGold(people,minenum - 1));
	}
	else
	{
		retMaxGold = GetMaxGold(people,minenum - 1);
	}

	//记录集
	dp[people][minenum] = retMaxGold;
	return retMaxGold;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();
	cout<<GetMaxGold(peopletotal,n - 1);
	return 0;
}