#include <iostream>
using namespace std;
const int maxn = 100000 + 100;

struct line
{
	double lp,rp;
	bool used;
}node[maxn];
int M;

int cmp(const void* a,const void* b)
{
	line* _a = (line* )a;
	line* _b = (line* )b;
	if(_a->lp != _b->lp)
		return (_a->lp - _b->lp) > 0 ? 1 : -1;
	else
		return (_a->rp - _b->rp) > 0 ? 1 : -1;
	return 0;
}

int segnum = 0;

void init()
{
	segnum = 0;
	double a,b;
	cin>>M;
	cin>>a>>b;
	while(a || b)
	{
		node[segnum].lp = a;
		node[segnum].rp = b;
		node[segnum].used = false;
		segnum++;
		cin>>a>>b;
	}//while
}

void solve()
{
	int res = 0;
	double tmax = 0.0;
	int record = -1;
	qsort(node,segnum,sizeof(node[0]),cmp);
	for(int i = 0;i < segnum;i++)
	{
		if(node[i].lp <= 0 && node[i].rp > tmax)
		{
			record = i;
			tmax = node[i].rp;
		}
	}//for int i
	if(-1==record)
	{
		cout<<"0"<<endl<<endl;
		return;
	}
	else
		res = 1;

	node[record].used = true;
	double limit = node[record].rp;

	for(int i = 0;i < segnum;i++)
  	{
		tmax = 0.0;
		if(!node[i].used && node[i].lp <= limit && node[i].rp > tmax)
		{
			record = i;
			tmax = node[i].rp;
		}
		if(0.0 != tmax)
		{	
			res++;
			node[record].used = true;
			limit = node[record].rp;
		}
		if(limit >= M)
			break;
	}
	if(limit >= M)
	{
		cout<<res<<endl;
		for(int i = 0;i < segnum;i++)
		{
			if(node[i].used)
				cout<<node[i].lp<<" "<<node[i].rp<<endl;
		}
	}
	else
		cout<<"0"<<endl;
	cout<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		init();
		solve();
	}
	return 0;
}