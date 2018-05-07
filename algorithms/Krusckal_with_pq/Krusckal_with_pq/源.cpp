#include <iostream>
#include <cstdlib>
#include <memory.h>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 15000 + 100;

//�洢��
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
int ans = 0;//��С��������Ȩ
int max_pr = 0;


int set_find(int a)
{
	if (set[a] < 0)
		return a;
	return set[a] = set_find(set[a]);
}

void set_join(int p, int q)//��p����q
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


//���㷨�������󶥶�
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

//����һ������󽨶ѣ��������insert��������
void build_max_heap()
{
	//�� i = edge_size ��д��i = node_size ....wa�˰���
	for (int i = edge_size / 2; i >= 1; i--)
		sink(i);
}


void heap_sort()
{
	build_max_heap();
	int size = edge_size;
	for (; edge_size >= 2;)
	{
		//����ط�edge[i] �տ�ʼ�����
		swap(edge[1], edge[edge_size]);
		//sink������Ҫedge_size���������������Ժ�����size�ָ�
		edge_size--;
		sink(1);
	}
	edge_size = size;
}

//�����ʱ�����������
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