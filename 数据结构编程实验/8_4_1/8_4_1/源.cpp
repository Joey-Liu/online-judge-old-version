#include <iostream>
using namespace std;

const int maxn = 500000 + 100;
int set[maxn];
int sum[maxn];

int set_find(int p)
{
	if(set[p] < 0)
		return p;
	return set[p] = set_find(set[p]);
}

void join(int p,int q)
{
	p = set_find(p);
	q = set_find(q);

	if(p != q)
	{	
		set[p] = q;
		sum[q] += sum[p];
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(set,-1,sizeof(set));
	int n,m,max;
	int a,b;
	
	while(cin>>n>>m)
	{
		memset(set,-1,sizeof(set));
		max = 0;

		for(long i = 0;i < n + 1;i++)
			sum[i] = 1;
		for(int i = 0;i < m;i++)
		{
			cin>>a>>b;
			join(a,b);
			max = sum[b] > max ? sum[b] : max;
		}
		cout<<max<<endl;
	}
	return 0;
}