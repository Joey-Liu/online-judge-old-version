#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int maxn = 500 + 50;
long long int k,m,a[maxn];//m本书 ， k位工人，a每本书的页数
long long int sum;//书的总页数
bool flag[maxn];//划分标致
int casenum;

void init()
{
	cin>>m>>k;
	for(int i = 1;i <= m;i++)
	{
		cin>>a[i];
		sum += a[i];
	}
}

bool judge(long long int page)
{
	memset(flag,false,sizeof(flag));
	int cnt = k;//剩余工人数量
	long long int now = 0;
	for(int n = m;n > 0;n--)
	{
		if(now + a[n] > page || n < cnt)//如果超出每个工人的工作量，或 剩下的书不够每人一本
		{
			now = a[n];
			flag[n] = true;
			cnt--;
		}
		else
			now += a[n];
		if(cnt <= 0 && n > 0)//工人已经被用完但是书还有
			return false;
	}
	return true;
}

void solve()
{
	long long int lp = 0,rp = sum,mid;
	for(int i = 1;i <=m;i++)
		if(lp < a[i])
			lp = a[i];

	while(lp + 1 < rp)
	{
		mid = (lp + rp)/2;
		if(judge(mid))
			rp = mid;
		else
			lp = mid + 1;
	}
	
	if(judge(lp))
		;
	else
		judge(rp);

	for(int i = 1;i <= m;i++)
	{
		cout<<a[i];
		if(i < m)
			cout<<" ";
		if(flag[i])
			cout<<"/ ";
	}
	cout<<endl;
}

int main()
{
	freopen("books.in","r",stdin);
	freopen("out.txt","w",stdout);

	cin>>casenum;
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}