#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 10000;

struct edge
{
	int x,y;
	int pr;
}E[maxn];//边集

int set[maxn];//并查集

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

int cmp(const void* a,const void* b)
{
	edge* _a = (edge* )a;
	edge* _b = (edge* )b;
	return ((_a->pr) - (_b->pr));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num,tmp;
	cin>>num;
	int k = 0;
	for(int i = 1;i <= num;i++)
	{
		int j = 1;
		for(j = 1;j <= i;j++)
			cin>>tmp;
		for(;j <= num;j++)
		{
			E[k].x = i;
			E[k].y = j;
			cin>>E[k++].pr;
		}
	}//for int i
	
	//边排序
	qsort(E,k,sizeof(E[0]),cmp);
	//节点初始化为树
	memset(set,-1,sizeof(set));
	
	int reanum,tp,tq;
	cin>>reanum;
	for(int i = 0;i < reanum;i++)
	{
		cin>>tp>>tq;
		join(tp,tq);
	}

	int result = 0;
	//kruskal
	for(int count = 0;count < k;count++)
	{
		if(set_find(E[count].x) != set_find(E[count].y) )
		{
			join(E[count].x,E[count].y);
			result += E[count].pr;
		}
	}
	cout<<result<<endl;
	return 0;
}