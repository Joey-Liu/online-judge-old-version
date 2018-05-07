#include <iostream>
#include <vector>

using namespace std;

int num[] = { 0, 4, 13 ,34, 8, 2, 10, 7, 13, 15, 22};
int SIZE = 10;


int patri(int lp, int rp)
{
	int tmp = num[rp];
	while (lp < rp)
	{
		while (lp < rp && num[lp] < tmp)
			lp++;
		num[rp] = num[lp];

		while (lp < rp && num[rp] >= tmp)
			rp--;
		num[lp] = num[rp];
	}//while lp < rp
	num[lp] = tmp;
	return lp;
}


void quick_sort(int lp, int rp)
{
	if (lp < rp)
	{
		int pos = patri(lp, rp);
		quick_sort(lp, pos - 1);
		quick_sort(pos + 1, rp);
	}

}

void heapify(int n)
{
	int lp = n * 2;
	int rp = n * 2 + 1;
	int smallest = n;

	if (lp <= SIZE && num[smallest] > num[lp])
		smallest = lp;
	if (rp <= SIZE && num[smallest] > num[rp])
		smallest = rp;
	
	if (smallest != n)
	{
		swap(num[n], num[smallest]);
		heapify(smallest);
	}
}

void build_heap()
{
	for (int i = SIZE / 2; i >= 0; i--)
	{
		heapify(i);
	}
}

void heap_sort()
{
	build_heap();
	while (SIZE > 0)
	{
		cout << num[1] << endl;
		swap(num[1], num[SIZE]);
		SIZE--;
		heapify(1);
	}
}


void merge(int lp, int rp, int mid)
{
	int *a = new int[mid - lp + 2];
	int *b = new int[rp - mid + 1];
	
	int ind = lp;
	for (int i = 0; i < mid - lp + 1; i++)
	{
		a[i] = num[ind];
		ind++;
	}
	a[mid - lp + 1] = 0x7fffffff;
	
	ind = mid + 1;
	for (int i = 0; i < rp - mid; i++)
	{
		b[i] = num[ind];
		ind++;
	}
	b[rp - mid] = 0x7fffffff;

	ind = lp;
	int ap = 0, bp = 0;
	while (ap <= mid - lp || bp <= rp - mid - 1)
	{
		int tmp;
		if (a[ap] < b[bp])
		{
			tmp = a[ap];
			ap++;
		}
		else
		{
			tmp = b[bp];
			bp++;
		}
		num[ind++] = tmp;
	}
}

void merge_sort(int lp, int rp)
{
	if (lp < rp)
	{
		int mid = (lp + rp) / 2;
		merge_sort(lp, mid);
		merge_sort(mid + 1, rp);
		merge(lp, rp, mid);
	}
}

int main()
{
	merge_sort(1, 10);
	for (int i = 1; i <= 10; i++)
		cout << num[i] << endl;
	cin.get();
}