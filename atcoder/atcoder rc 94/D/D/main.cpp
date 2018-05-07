#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

typedef long long LL;

LL Q, A, B;

LL work()
{
	LL sq = LL(sqrt(A * B));
	LL ans = sq * 2 - 1;
	if (A == B)
		ans -= 1;
	else if (sq * sq == A * B)
		ans -= 2;
	else if (sq * (sq + 1) >= A * B)
		ans -= 1;
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> A >> B;
		LL res = work();
		cout << res << endl;
	}
	return 0;
}