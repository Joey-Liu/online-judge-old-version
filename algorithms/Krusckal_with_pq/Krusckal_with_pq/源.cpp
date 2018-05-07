#include <iostream>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 15000 + 100;

//存储边
struct side
{
	int lp;
	int rp;
	int pr;
	bool used;

	side()
	{
		used = false;
	}
}edge[maxn];
int edge_size = 0;
int node_size = 0;

int set[1100];
int ans = 0;//最小生成树的权
int max_pr = 0;


int set_find(int a)
{
	if (set[a] < 0)
		return a;
	return set[a] = set_find(set[a]);
}

void set_join(int p, int q)//把p并入q
{
	p = set_find(p);
	q = set_find(q);
	if (p != q)
		set[p] = q;
}

int cmp(const void* a, const void* b)
{
	side* _a = (side*)a;
	side* _b = (side*)b;
	
	return (_a->pr - _b->pr);
}

void swap(side & a, side & b)
{
	side t = a;
	a = b;
	b = t;
}


//堆算法，建立大顶堆
void swim(int k)
{
	while (k > 1 && cmp(&edge[k], &edge[k / 2]) > 0)
	{
		swap(edge[k], edge[k / 2]);
		k /= 2;
	}
}

void sink(int k)
{
	while (2 * k <= edge_size)
	{
		int son = 2 * k;
		if (son + 1 <= edge_size && cmp(&edge[son], &edge[son + 1]) < 0)
			son++;
		if (cmp(&edge[k], &edge[son]) >= 0)
			break;
		swap(edge[k], edge[son]);
		k = son;
	}
}

//可以一次输完后建堆，否则调用insert函数建堆
void build_max_heap()
{
	//把 i = edge_size 错写成i = node_size ....wa了半天
	for (int i = edge_size / 2; i >= 1; i--)
		sink(i);
}


void heap_sort()
{
	build_max_heap();
	int size = edge_size;
	for (; edge_size >= 2;)
	{
		//这个地方edge[i] 刚开始打错了
		swap(edge[1], edge[edge_size]);
		//sink函数需要edge_size，所以先做处理，以后再用size恢复
		edge_size--;
		sink(1);
	}
	edge_size = size;
}

//做题的时候不用这个函数
/*
void insert(side s)
{
	edge[++edge_size] = s;
	swim(edge_size);
}
*/

void Kruskal()
{
	heap_sort();
	//qsort(edge + 1, edge_size, sizeof(side), cmp);
	memset(set, -1, sizeof(set));
	ans = 0;

	for (int i = 1; i <= edge_size; i++)
	{
		if (set_find(edge[i].lp) != set_find(edge[i].rp))
		{
			edge[i].used = true;
			set_join(edge[i].lp, edge[i].rp);
			ans += edge[i].pr;
			max_pr = edge[i].pr;
		}
	}//for
}

int main()
{
	freopen("08", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> node_size >> edge_size;

	for (int i = 1; i <= edge_size; i++)
		cin >> edge[i].lp >> edge[i].rp >> edge[i].pr;
	
	Kruskal();
	cout << max_pr << endl;
	cout << node_size - 1 << endl;
	for (int i = 1; i <= edge_size; i++)
	{
		if (edge[i].used)
			cout << edge[i].lp << " " << edge[i].rp << endl;
	}
	return 0;
}