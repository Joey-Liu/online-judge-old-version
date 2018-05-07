#include <iostream>
using namespace std;

const int maxn = 15000 + 100;
const int nodesize = 1000 + 100;
struct edge
{
	int x,y;
	int pr;
	bool used;
}E[maxn];

int set[nodesize];

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

int cmp(const void* a,const void* b)
{
	edge* _a = (edge *)a;
	edge* _b = (edge *)b;

	return ((_a->pr) - (_b->pr));
}

int main()
{
	freopen("08","r",stdin);
	freopen("out.txt","w",stdout);
	int nodenum,edgenum;
	cin>>nodenum>>edgenum;
	for(int i = 0;i < edgenum;i++)
	{
		cin>>E[i].x>>E[i].y>>E[i].pr;
		E[i].used = false;
	}

	qsort(E,edgenum,sizeof(E[0]),cmp);
	memset(set,-1,sizeof(set));

	int res = 0,maxpr = 0;
	for(int cnt = 0;cnt < edgenum;cnt++)
	{
		if(set_find(E[cnt].x) != set_find(E[cnt].y)) 
		{
			join(E[cnt].x,E[cnt].y);
			res += E[cnt].pr;
			E[cnt].used = true;
			maxpr = E[cnt].pr;
		}
	}
	cout<<maxpr<<endl;
	cout<<nodenum - 1<<endl;
	for(int i = 0;i < edgenum;i++)
		if(E[i].used)
			cout<<E[i].x<<" "<<E[i].y<<endl;

	return 0;
}