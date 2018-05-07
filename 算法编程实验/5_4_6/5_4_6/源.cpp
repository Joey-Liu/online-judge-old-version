//从上到下 从左到右，依次枚举，看对应矩形中元素是否相同，若不相同则进行操作，这样可以保证有一个元素与目标矩形相同
#include <iostream>
using namespace std;

const int maxn = 100 + 30;
int map[maxn][maxn];
int pic[maxn][maxn];
int n,m,r,c;

void init()
{
	memset(map,0,sizeof(map));
	memset(pic,0,sizeof(pic));

	char c;
	getchar();
	for(int i = 1;i <= n;i++)
		for(int j =1;j <= m;j++)
		{
			c = getchar();
			map[i][j] = c -'0';
			if(j==m)
				getchar();
		}
}

void solve()
{
	int res = 0;
	for(int i = 1;i <= n -r + 1;i++)
	{
		for(int j = 1;j <= m - c +1;j++)
		{
			if(pic[i][j] != map[i][j])
			{
				res++;
				for(int ti = i;ti <= i + r -1;ti++)
					for(int tj = j;tj <= j + c -1;tj++)
						pic[ti][tj] ^= 1;
			}
		}// int i
	}//int j
	
	bool flag = true;
	for(int i =1;i <= n;i++)
		for(int j =1;j <= m;j++)
			if(pic[i][j] != map[i][j])
				flag = false;
	if(flag)
		cout<<res<<endl;
	else
		cout<<"-1"<<endl;
}

int main()
{
	freopen("annoying.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>n>>m>>r>>c;
	while(n || m|| r || c)
	{
		init();
		solve();
		cin>>n>>m>>r>>c;
	}
	return 0;
}