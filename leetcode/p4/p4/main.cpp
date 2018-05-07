#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#define MIN(x, y) ((x) < (y) ? x : y)

using namespace std;

int findKthElement(int a1[], int len1, int a2[], int len2, int k)
{
	if (k == 1)
	{
		if (len1 > 0 && len2 > 0)
			return MIN(a1[0], a2[0]);
		else if (len1 > 0)
			return a1[0];
		else
			return a2[0];
	}
	if (len1 == 0)
		return a2[k - 1];
	if (len2 == 0)
		return a1[k - 1];

	int i = MIN(k / 2, len1);
	int j = MIN(k / 2, len2);

	if (a1[i - 1] < a2[j - 1])
		return findKthElement(a1 + i, len1 - i, a2, len2, k - i);
	else
		return findKthElement(a1, len1, a2 + j, len2 - j, k - j);
}

double findMedianSortedArrays(int* nums1, int nums1Size,
	int* nums2, int nums2Size) 
{
	int m = (nums1Size + nums2Size + 1) >> 1;
	int n = (nums1Size + nums2Size + 2) >> 1;

	int me1 = findKthElement(nums1, nums1Size, nums2, nums2Size, m);
	int me2 = findKthElement(nums1, nums1Size, nums2, nums2Size, n);
	return double(me1 + me2) / 2.0;
}

int main()
{
	int a[] = { 1, 3 };
	int b[] = { 2 };
	cout << findMedianSortedArrays(a, 2, b, 1);
	getchar();
}