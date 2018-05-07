#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 1000+ 10;
struct com
{
	double x,y;
}puter[maxn];

int set[maxn];
bool valid[maxn];

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
	memset(valid,false,sizeof(valid));
	memset(set,-1,sizeof(set));
	
	int N,d;
	cin>>N>>d;
	for(int i = 0;i < N;i++)
		cin>>puter[i].x>>puter[i].y;

	int a,b;
	char c;
	while(cin>>c)
	{
		if('O'==c)
		{
			cin>>a;
			a--;
			valid[a] = true;
			for(int i = 0;i < N;i++)
			{
				if(valid[i] && pow(puter[i].x - puter[a].x,2) + pow(puter[i].y - puter[a].y,2) <= pow((double)d,2) )
					join(i,a);
			}
		}
		else
		{
			cin>>a>>b;
			a--;
			b--;
			if(set_find(a)==set_find(b))
				cout<<"SUCCESS"<<endl;
			else
				cout<<"FAIL"<<endl;
		}
	}
	return 0;
}