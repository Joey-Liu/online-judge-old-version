#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 5000;
const int node_size = 100 + 10;
int node,edgenum;
int res;
int pre;
bool t_unique;

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

	for(int i = 0;i < edgenum;i++)
		cin>>E[i].x>>E[i].y>>E[i].pr;
}

void solve()
{
	memset(set,-1,sizeof(set));
	qsort(E,edgenum,sizeof(E[0]),cmp);
	t_unique = true;
	
	int index;//pre 为上次枚举时最小生成树权和
	for(index = 0;index < edgenum;index++)//从最小的边开始枚举产生的生成树
	{	
		memset(set,-1,sizeof(set));
		int cnt = 0;//判断是否产生生成树
		int ans = 0;

		for(int i = index;i < edgenum;i++)
		{
			if(set_find(E[i].x) != set_find(E[i].y))
			{
				join(E[i].x,E[i].y);
				cnt++;
				ans += E[i].pr;
			}
			if(cnt==node - 1)
				break;
		}
		if(0==index && cnt==node - 1)
			pre = ans;
		else if(cnt==node - 1 && pre==ans && index != 0)
		{	
			t_unique = false;
			break;
		}
	}//for index
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;

	while(casenum--)
	{
		cin>>node>>edgenum;
		init();
		solve();
		if(t_unique)
			cout<<pre<<endl;
		else
			cout<<"Not Unique!"<<endl;
	}
	return 0;
}