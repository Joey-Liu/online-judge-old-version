#include <iostream>
using namespace std;

const int maxn = 30;

int eve[maxn];
int stu[maxn];
int tmp[maxn];
int c[maxn][maxn];
int n;

void solve()
{
	for(int i = 1;i <= n;i++)
		c[i][0] = c[0][i] = 0;
	
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(eve[i]==stu[j])
				c[i][j] = c[i -1][j - 1] + 1;
			else if(c[i -1][j] >= c[i][j - 1])
				c[i][j] = c[i -1][j];
			else
				c[i][j] = c[i][j -1];
}

int main()
{
	freopen("111.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n;
	for(int i =1;i <= n;i++)
	{
		cin>>tmp[i];
		eve[tmp[i]] = i;
	}

	char ch;
	while(cin>>ch)
	{
		cin.unget();
		for(int i =1;i <= n;i++)
		{		
			cin>>tmp[i];
			stu[tmp[i]] = i;
		}
		solve();
		cout<<c[n][n]<<endl;
	}
	return 0;
}
