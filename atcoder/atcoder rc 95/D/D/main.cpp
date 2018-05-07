#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = 100000 + 50;
int N, A[maxn];

int bi_search_lb(int target) {
	int lp = 0, rp = N - 1;
	while (lp < rp) {
		int mid = lp + (rp - lp) / 2;
		if (A[mid] >= target)
			rp = mid;
		else
			lp = mid + 1;
	}
	return lp;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N);
	int mid = A[N - 1] / 2;

	int dist = 0x7fffffff, res = -1;
	for (int i = 0; i < N - 1; i++) {
		if (abs(mid - A[i]) < dist) {
			res = i;
			dist = abs(mid - A[i]);
		}
	}

	if (A[N - 1] % 2) {
		mid += 1;
		for (int i = 0; i < N - 1; i++) {
			if (abs(mid - A[i]) < dist) {
				res = i;
				dist = abs(mid - A[i]);
			}
		}
	}
	cout << A[N - 1] << " " << A[res] << endl;
	return 0;
}