#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

const int maxn = 1000 + 100;
struct island
{
	double lp,rp;
}node[maxn];
bool solution = true;

void init(int n,int d)
{
	double x,y;
	for(int i = 0;i < n;i++)
	{
		cin>>x>>y;
		if(y > d)
		{
			solution = false;
			return;
		}
		double h = sqrt(d*d - y*y);
		node[i].lp = x - h;
		node[i].rp = x + h;
	}
}

int cmp(const void* a,const void* b)
{
	island* _a = (island* )a;
	island* _b = (island* )b;

	if(_a->rp != _b->rp)//应该先考虑右结点，先按右结点递增顺序
		return (_a->rp - _b->rp) > 0 ? 1 : -1;
	return (_a->lp - _b->lp) > 0 ? 1 : -1;
	return 0;
}

/*
bool cmp(island a,island b)
{
	if(a.rp < b.rp)
		return true;
	if(a.rp==b.rp && a.lp < b.lp)
		return true;
	return false;
}
*/
int main()
{
	freopen("input","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 1;
	int num,distance;
	cin>>num>>distance;
	while(num || distance)
	{
		solution = true;
		init(num,distance);
		qsort(node,num,sizeof(node[0]),cmp);
		//sort(node,node + num,cmp);

		if(solution)
		{
			int radar = 0;
			double position = -100000000;

			for(int i = 0;i < num;i++)
			{
				if(position < node[i].lp)
				{
					radar++;
					position = node[i].rp;
				}
			}//for
			cout<<"Case "<<casenum++<<": "<<radar<<endl;
		}//if
		else
		{
			cout<<"Case "<<casenum++<<": -1"<<endl;
		}
		cin>>num>>distance;
	}//while num
	return 0;
}