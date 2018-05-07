#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;

const int maxn = 15000 + 50;
const int maxnode = 1000 + 100;
struct edge
{
	int x,y;
	int pr;
}E[maxn];

struct ans
{
	int x,y;
}res[maxn];

int cmp(const void* a,const void* b)
{
	edge* _a = (edge* )a;
	edge* _b = (edge* )b;
	return (_a->pr - _b->pr);
}

int set[maxnode];//并查集
int set_find(int p)
{
	if(set[p] < 0)
		return p;
	return set[p] = set_find(set[p]);
}

void join(int p,int q)//把p加入q
{
	p = set_find(p);
	q = set_find(q);
	if(p != q)
		set[p] = q;
}

int main()
{
	freopen("01","r",stdin);
	freopen("out.txt","w",stdout);
	int N;int M;
	int k;
	memset(set,-1,sizeof(set));

	cin>>N>>M;
	for(k = 0;k < M;k++)
		cin>>E[k].x>>E[k].y>>E[k].pr;

	qsort(E,k,sizeof(E[0]),cmp);
	long mark = 0;
	int res_count = 0;
	for(int i = 0;i < k;i++)
	{
		if(set_find(E[i].x) != set_find(E[i].y))
		{
			join(E[i].x,E[i].y);
			res[res_count].x = E[i].x;
			res[res_count].y = E[i].y;
			res_count++;
			mark = i;
		}
	}

	cout<<E[mark].pr<<endl;
	cout<<N-1<<endl;
	for(int i = 0;i < res_count;i++)
		cout<<res[i].x<<" "<<res[i].y<<endl;
	return 0;
}