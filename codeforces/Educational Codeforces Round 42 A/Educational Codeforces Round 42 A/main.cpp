#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;
const int maxn = 200000 + 50;
int suffix[maxn], N;

int bi_search(int val) {
	
	int lp = 1, rp = N, mid;
	while (lp < rp) {
		mid = lp + (rp - lp) / 2;
		if (suffix[mid] >= val)
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
	for (int i = 1; i <= N; i++) {
		cin >> suffix[i];
		suffix[i] += suffix[i - 1];
	}

	int half_p = suffix[N] / 2;
	if (half_p * 2 < suffix[N])
		half_p += 1;
	int ans = bi_search(half_p);
	cout << ans << endl;


	return 0;
}