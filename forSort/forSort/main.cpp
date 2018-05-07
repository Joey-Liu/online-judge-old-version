#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int partition(int numbers[], int lp, int rp) {
	int piv = numbers[rp];
	int x = lp, y = rp;
	while (x < y) {
		while (x < y && numbers[x] <= piv)
			x++;
		numbers[y] = numbers[x];
		while (x < y && numbers[y] >= piv)
			y--;
		numbers[x] = numbers[y];
	}
	numbers[x] = piv;
	return x;
}

void mqsort(int numbers[], int lp, int rp) {
	if (lp < rp) {
		int ind = partition(numbers, lp, rp);
		mqsort(numbers, lp, ind - 1);
		mqsort(numbers, ind + 1, rp);
	}
}


void merge(int numbers[], int lp, int rp, int mid, int T[]) {
	int x = lp, y = mid + 1, ind = x;
	while (x <= mid || y <= rp) {
		if (y > rp || (x <= mid && numbers[x] <= numbers[y]))
			T[ind++] = numbers[x++];
		else
			T[ind++] = numbers[y++];
	}
	for (int i = lp; i < ind; i++) {
		numbers[i] = T[i];
	}
}

void merge_sort(int numbers[], int lp, int rp, int T[]) {
	if (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		merge_sort(numbers, lp, mid, T);
		merge_sort(numbers, mid + 1, rp, T);
		merge(numbers, lp, rp, mid, T);
	}
}

void buble(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		bool flag = false;
		for (int j = 0; j < length - 1 - i; j++) {
			if (numbers[j] > numbers[j + 1]) {
				flag = true;
				swap(numbers[j], numbers[j + 1]);
			}
		}
		if (!flag)
			break;
	}
}

void choose(int numbers[], int length) {
	for (int i = 0; i < length; i++) {
		int mini = 0x7fffffff, ind = -1;
		for (int j = i + 1; j < length; j++) {
			if (mini > numbers[j]) {
				mini = numbers[j];
				ind = j;
			}
		}
		if (mini < numbers[i])
			swap(numbers[ind], numbers[i]);
	}
}

void insert_sort(int numbers[], int length) {
	for (int i = 1; i < length; i++) {
		int piv = numbers[i], j = i - 1;
		for (j = i - 1; j >= 0; j--) {
			if (numbers[j] >= piv)
				numbers[j + 1] = numbers[j];
			else
				break;
		}//for j
		numbers[j + 1] = piv;
	}
}



int a[] = { 1,2,3,4,5,6,7,8, 34,1,2,123,-192,49 };
int main()
{
	
	int size = sizeof(a) / sizeof(int);
	cout << size << endl;
	//mqsort(a, 0, size - 1);
	
	int *T = new int[size];
	//merge_sort(a, 0, size - 1, T);
	//buble(a, size);
	//choose(a, size);
	insert_sort(a, size);

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	int b;
	cin >> b;
	return 0;
}