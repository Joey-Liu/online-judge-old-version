#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[] = { 5 ,4,324,11,234,-929,123488,5};
int num = sizeof(arr) / sizeof(int);

int bi_search(int n, int lp, int rp)
{
	
	while (lp < rp)
	{
		int mid = (lp + rp) / 2;
		if (arr[mid] < n)
			lp = mid + 1;
		else if (arr[mid] > n)
			rp = mid - 1;
		else
			return mid;
	}
	return lp;
}


void insert_sort()
{
	for (int i = 0; i < num - 1; i++)
	{
		int j = i + 1;
		if (arr[j] > arr[i])
			continue;
		//int n = lower_bound(arr, arr + i, arr[j]) - arr;
		int n = bi_search(arr[j], 0, i);
		int tmp = arr[j];
		for (int k = j; k > n; k--)
			arr[k] = arr[k - 1];
		arr[n] = tmp;
	}//for int i
}

void choose_sort()
{
	for (int i = 0; i < num; i++)
	{
		int mini = arr[i], index = i;
		for (int j = i + 1; j < num; j++)
		{
			if (arr[j] < mini)
			{
				mini = arr[j];
				index = j;
			}
		}//for intj 
		int tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
}

int main()
{
	//choose_sort();
	insert_sort();
	for (int i = 0; i < num; i++)
		cout << arr[i] << endl;
	int a;;
	cin >> a;
	return 0;

}