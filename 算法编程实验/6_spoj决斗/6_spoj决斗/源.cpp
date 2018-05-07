#include <iostream>
using namespace std;

const int maxn = 100 + 50;
int meet[maxn][maxn];//-1 尚未明确，0 不可能 1 可能
int bmat[maxn][maxn];//决斗矩阵,标号基于1
int st[maxn];//将换拆成链

int n;//人数
int seva = 0;//生还人数
bool men[maxn];//生还标识
int casenum;

void init()
{
	cin>>n;
	char ch;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
		{
			cin>>ch;
			bmat[i][j] = ch - '0';
		}
}

int dp(int i,int j)//i,j是否能相遇 ,i ,j 为新链中标号
{
	if(-1 != meet[i][j])
		return meet[i][j];
	else
	{   
		bool flag = false;
		int k = i +1;
		for(k = i + 1;k < j;k++)
		{
			if(dp(i,k) && dp(k,j) && (bmat[st[i] ][st[k] ] || bmat[st[j] ][st[k] ]))
			{
				flag = true;
				break;
			}
		}
		if( true==flag)
			return 	(meet[i][j] = 1);
		else
			return (meet[i][j] = 0);
	}
}

//把meet表重新改一遍应该就好
void solve()
{
	seva = 0;
	for(int i = 1;i <= n;i++)//枚举每个结点
	{
		memset(meet,-1,sizeof(meet));
		int num = 1;//新链中标号
		for(int j = i;j <= n;j++)
			st[num++] = j;
		for(int j = 1;j < i;j++)
			st[num++] = j;
		st[num] = i;

		for(int j = 1;j <= n;j++)
			meet[j][j +1] = 1;

		if(1==dp(1,num))
		{
			seva++;
			men[i] = true;
		}
	}
	cout<<seva<<endl;
	for(int i = 1;i <= n;i++)
		if(men[i])
			cout<<i<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>casenum;
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}