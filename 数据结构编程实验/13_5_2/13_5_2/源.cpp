//尚未通过，tle
#include <iostream>
using namespace std;

const int maxn = 50000 + 100;
const int maxsize = INT_MAX;
const long long INF=(long long)1<<63-1;
int weight[maxn];
struct edge
{
	int lp;
	int rp;
	int val;
}E[maxn * 2];//边集

long long int dist[maxn];//到根节点距离
bool flag[maxn];//队列
int v,e;

int cmp(const void* a,const void* b)
{
	edge* _a = (edge*)a;
	edge* _b = (edge*)b;
	return (_a->lp - _b->lp);
}


void init()
{
	scanf("%d%d",&v,&e);
	for(int i = 1;i <= v;i++)
		scanf("%d",&weight[i]);
	for(int i = 1;i <= e * 2;i++)
	{
		int from,to,tmp;
		scanf("%d%d%d",&from,&to,&tmp);
		E[i].lp = from;
		E[i].rp = to;
		E[i].val = tmp;
		i++;
		E[i].lp = to;
		E[i].rp = from;
		E[i].val = tmp;
	}
	qsort(E,2 * e,sizeof(E[0]),cmp);
}

void solve()
{
	for(int i = 0;i <= v;i++)
		dist[i] = INF;

	memset(flag,false,sizeof(flag));

	dist[1] = 0;
	while(true)
	{
		int next = -1;
		int w = maxsize;
		for(int i = 1;i <= v;i++)
		{
			if(!flag[i] && dist[i] < w)
			{
				next = i;
				w = dist[i];
			}
		}
		if(-1==next)
			break;
		flag[next] = true;
		for(int i = 1;i <= 2 * e;i++)
		{
			//if(!flag[i] && E[i].lp==next && dist[E[i].rp] > w + E[i].val)
			//	dist[E[i].rp] = w + E[i].val;
			if(E[i].lp < next)
				continue;
			else if(E[i].lp==next)
			{
				if(!flag[E[i].rp] && dist[E[i].rp] > w + E[i].val)
				{
					dist[E[i].rp] = w + E[i].val;
				}
			}//else if
			else
				break;
		}
	}//while true
	long long  res = 0;
	bool answer = true;
	for(int i = 1;i <= v;i++)
		if(dist[0]==dist[i])
			answer = false;
	if(answer)
	{
		for(int i = 1;i <= v;i++)
			res += weight[i] * dist[i];
		cout<<res<<endl;
		printf("%llf",res);
	}
	else
		printf("No Answer\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}