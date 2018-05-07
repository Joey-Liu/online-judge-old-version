#include <iostream>
using namespace std;

const int maxn = 15;
int r[maxn];//r[i]长度为i时的最大收益
int p[maxn];//p[i]长度为i时的价格
int s[maxn];//s[i]长度为i时 取得最大收益时第一段切割长度

void dp(int n)//n钢条长度
{
	memset(r,-1,sizeof(r));
	memset(s,-1,sizeof(s));
	r[0] = 0;

	for(int j = 1;j <= n;j++)
	{
		int q = -1;
		for(int i = 1;i <= j;i++)
		{
			if(q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
			r[j] = q;
		}//for int i
	}//for int j
}

void init(int num)
{
	p[0] = 0;
	for(int i = 1;i <= num;i++)
		cin>>p[i];
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init(10);
	dp(10);

	int n = 7;
	cout<<r[n]<<endl;
	while(n > 0)
	{
		cout<<s[n]<<"  ";
		n -= s[n];
	}
	return 0;
}