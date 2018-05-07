#include <iostream>
using namespace std;

const int maxn = 50000 + 100;
int set[maxn];

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
		set[p] = q;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	int casenum = 1;
	cin>>n>>m;
	while(n || m)
	{
		int num = 0;
		memset(set,-1,sizeof(set));
		int x,y;
		for(int i = 0;i < m;i++)
		{
			cin>>x>>y;
			join(x,y);
		}

		for(int i = 1;i <= n;i++)
			if(set[i] < 0)
				num++;
		cout<<"Case "<<casenum<<": "<<num<<endl;
		
		casenum++;
		cin>>n>>m;
	}
	return 0;
}