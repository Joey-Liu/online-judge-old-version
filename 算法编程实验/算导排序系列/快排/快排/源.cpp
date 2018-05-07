#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn = 50;

int a[maxn] = {2,8,7,1,3,5,6,4};
int Size = 8;

/*
int partition(int p,int r)//以a[r]为基准元素比较
{
	int tmp = a[r];
	int i = p - 1;
	for(int j = p;j < r;j++)
	{
		if(a[j] < tmp)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i + 1],a[r]);
	return i + 1;
}
*/

int partition(int lp,int rp)
{
	int tmp = a[rp];
	while(lp < rp)
	{
		while(a[lp] <= tmp && lp < rp)
			lp++;
		a[rp] = a[lp];

		while(a[rp] >= tmp && lp < rp)
			rp--;
		a[lp] = a[rp];
	}
	a[lp] = tmp;
	return lp;
}

void quick_sort(int p,int r)
{
	if(p < r)
	{
		int pos = partition(p,r);
		quick_sort(p,pos - 1);
		quick_sort(pos + 1,r);
	}
}

int main()
{
	freopen("out.txt","w",stdout);
	quick_sort(0,7);
	for(int i = 0;i < Size;i++)
		cout<<a[i]<<" ";
	return 0;
}
