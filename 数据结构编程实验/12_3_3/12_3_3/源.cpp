#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 5000;
const int node_size = 100 + 10;
int node,edgenum;
bool istree = false;
int slim;

struct edge
{
	int x,y;
	int pr;
}E[maxn];

int set[node_size];

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
	edge* _a = (edge* )a;
	edge* _b = (edge* )b;
	return ((_a->pr) - (_b->pr));
}

void init()
{
	memset(set,-1,sizeof(set));
	int cnt = 0;

	for(int i = 0;i < edgenum;i++)
	{	
		cin>>E[i].x>>E[i].y>>E[i].pr;
		if(set_find(E[i].x) != set_find(E[i].y))
		{
			join(E[i].x,E[i].y);
			cnt++;
		}
	}
	if(cnt < node - 1)
		istree = false;
	else
		istree = true;
}

void solve()
{
	memset(set,-1,sizeof(set));
	qsort(E,edgenum,sizeof(E[0]),cmp);
	if(!istree)
		slim = -1;
	else
	{
		slim = 16000000;
		int index,pre = -1;//pre 为上次枚举时最小边权
		for(index = 0;index < edgenum;index++)//从最小的边开始枚举产生的生成树
		{
			memset(set,-1,sizeof(set));
			int cnt = 0;//判断是否产生生成树
			int maxpr = -1;
			while(E[index].pr==pre)
				index++;

			for(int i = index;i < edgenum;i++)
			{
				if(set_find(E[i].x) != set_find(E[i].y))
				{
					join(E[i].x,E[i].y);
					maxpr = E[i].pr;
					cnt++;
				}
				if(cnt==node - 1)
					break;
			}
			if(node - 1==cnt)
				slim = min(slim,maxpr - E[index].pr);

			pre = E[index].pr;
		}//for index
	}//else
}

int main()
{
	freopen("F.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>node>>edgenum;
	while(node || edgenum)
	{
		init();
		solve();
		cout<<slim<<endl;
		cin>>node>>edgenum;
	}
	return 0;
}