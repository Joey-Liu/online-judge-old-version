#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>

using namespace std;
const int maxn = 200000 + 50;
int N, X[maxn], nu[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> X[i];
		nu[i] = X[i];
	}
	sort(nu, nu + N);

	int mid = N / 2;
	int lm = nu[mid - 1], rm = nu[mid];
	for (int i = 0; i < N; i++) {
		if (X[i] <= lm)
			cout << rm << endl;
		else
			cout << lm << endl;
	}
	return 0;
}