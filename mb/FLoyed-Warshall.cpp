#include <iostream>
#include <string>
#include <map>
using namespace std;

const int maxn = 50;
map<string,int> record;//记录货币 和编号
long double dis[maxn][maxn];//最长路径

void init(int casenum,int n)
{
	record.clear();
	memset(dis,0,sizeof(dis));

	string str;
	for(int i = 0;i < n;i++)
	{
		cin>>str;
		record[str] = i;
	}

	int m;
	cin>>m;
	string s1,s2;
	double r;
	for(int i = 0;i < m;i++)
	{
		cin>>s1>>r>>s2;
		dis[record[s1] ][record[s2] ] = r;
	}
}

void solve(int casenum,int n)
{
	for(int k = 0;k < n;k++)
		for(int i = 0;i < n;i++)
			for(int j = 0;j < n;j++)
				if(dis[i][j] < dis[i][k] * dis[k][j])
					dis[i][j] = dis[i][k] * dis[k][j];

	bool flag = false;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(dis[i][j] * dis[j][i] > 1)
				flag = true;
	if(flag)
		cout<<"Case "<<casenum<<": "<<"Yes"<<endl;
	else
		cout<<"Case "<<casenum<<": "<<"No"<<endl;
}


int main()
{
	//freopen("arbitrage.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int casenum = 1;
	int num;
	while(cin>>num && num != 0)
	{
		init(casenum,num);
		solve(casenum,num);
		casenum++;
	}
	return 0;
}
