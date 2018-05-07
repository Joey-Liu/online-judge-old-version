#include <iostream>
#include <math.h>
using namespace std;

const int maxn = 0x7fffffff;
const int size = 8;

int a[size] = {5,2,4,7,1,3,2,6};

void merge(int p,int q,int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int la[size],ra[size];
	for(int i = 1;i <= n1;i++)	//p ----- q
		la[i] = a[p + i - 1];
	for(int i = 1;i <= n2;i++)	//q + 1 ------ r
		ra[i] = a[q + i];

	la[n1 + 1] = maxn;
	ra[n2 + 1] = maxn;

	int i,j;
	i = j = 1;
	for(int k = p;k <= r;k++)
	{
		if(la[i] <= ra[j])
		{
			a[k] = la[i];
			i++;
		}
		else
		{
			a[k] = ra[j];
			j++;
		}
	}
}

void merge_sort(int p,int r)
{
	if(p < r)
	{
		int q = (p + r) / 2;
		merge_sort(p,q);
		merge_sort(q + 1,r);
		merge(p,q,r);
	}
}

int main()
{
	freopen("out.txt","w",stdout);
	merge_sort(0,7);
	for(int i = 0;i < size;i++)
		cout<<a[i]<<endl;
	return 0;
}