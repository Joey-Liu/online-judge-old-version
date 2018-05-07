//大顶堆
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
const int maxn = 100;
int a[maxn] = {0,4,1,3,2,16,9,10,14,8,7};//从1开始存储
int Size = 10;//排序元素数量

void heapify(int num)//对下标num元素构造堆
{
	int largest = num;
	int lp = num * 2;
	int rp = lp + 1;

	if(lp <= Size && a[lp] > a[num])
		largest = lp;
	if(rp <= Size && a[rp] > a[largest])
		largest = rp;
	if(largest != num)
	{
		swap(a[num],a[largest]);
		heapify(largest);
	}
}

void heapify(int num)
{
	int largest = num;
	int lp = num * 2;
	int rp = lp + 1;
	
	if(lp <= Size && a[lp] > a[largest])
		largest = lp;
	if(rp <= Size && a[rp] > a[largest])
		largest = rp;
	if(largest != num)
	{
		swap(a[largest], a[num]);
		heapify(largest);
	}
}

void build_heap()
{
	if(Size != 0)
	{
		for(int i = Size / 2;i >= 1;i--)
			heapify(i);
	}
}

void heap_sort()
{
	build_heap();
	for(int i = Size;i >= 1;i--)
	{
		cout<<a[1]<<" ";
		swap(a[1],a[Size]);
		Size--;
		heapify(1);
	}
}

int main()
{
	freopen("out.txt","w",stdout);
	heap_sort();
	return 0;
}