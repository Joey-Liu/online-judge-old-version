#include <iostream>
using namespace std;

const int maxn = 50000 + 100;
struct interval
{
	int lp,rp;
}s[maxn];

int cmp(const void * a,const void * b)
{
	interval* _a = (interval *)a;
	interval* _b = (interval *)b;
	return (_a->lp - _b->lp);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	cin>>num;
	for(int i = 0;i < num;i++)
		cin>>s[i].lp>>s[i].rp;

	qsort(s,num,sizeof(s[0]),cmp);

	int st = s[0].lp,en = s[0].rp;
	for(int i = 1;i < num;i++)
	{
		if(s[i].lp <= en && s[i].rp >= en)// = 主要是为了不进行 区间输出
		{
			en = s[i].rp;
		}
		else if(en < s[i].lp)
		{
			cout<<st<<" "<<en<<endl;
			st = s[i].lp;
			en = s[i].rp;
		}
	}
	cout<<st<<" "<<en<<endl;
	return 0;
}