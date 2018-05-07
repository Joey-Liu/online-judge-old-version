#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <time.h>

using namespace std;

int partition(int a[], int lp, int rp)
{
	int tmp = a[lp];
	while (lp < rp)
	{
		while (lp < rp && a[rp] >= tmp)
			rp--;
		a[lp] = a[rp];

		while (lp < rp && a[lp] <= tmp)
			lp++;
		a[rp] = a[lp];
	}
	a[lp] = tmp;
	return lp;
}

int rand_partition(int a[], int lp, int rp)
{
	int index = rand() % (rp - lp + 1);		//index ·¶Î§Ó¦¸ÃÊÇ lp---rp
	index += lp;
	swap(a[lp], a[index]);
	return partition(a, lp, rp);
}

void rand_quicksort(int a[], int lp, int rp)
{
	if (lp < rp)
	{
		int q = rand_partition(a, lp, rp);
		rand_quicksort(a, lp, q - 1);
		rand_quicksort(a, q + 1, rp);
	}
}

int rand_select(int a[], int lp, int rp,int index)
{
	if (lp == rp)
		return a[lp];
	
	int q = rand_partition(a, lp, rp);
	int k = q - lp + 1;
	if (index == k)
		return a[q];
	else if (index < k)
		return rand_select(a, lp, q - 1, index);
	else
		return rand_select(a, q + 1, rp, index - k);

}


const int maxn = 150;
int num[maxn];

int main()
{
	freopen("out.txt", "w", stdout);
	srand(time(0));
	//int num[maxn];
	for (int i = 0; i < maxn; i++)
		num[i] = rand() % 201;

	cout << rand_select(num, 0, maxn - 1, 13)<<endl<<endl;
	rand_quicksort(num, 0, maxn - 1);
	for (int i = 0; i < maxn; i++)
	{
		if (i == 12)
			cout << "Here it is! ";
		cout << num[i] << endl;
	}
	return 0;
}