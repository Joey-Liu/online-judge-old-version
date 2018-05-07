#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
const int maxn = 20000 + 100;

double val[maxn], avg = 0.0, abo_sm = 0.0, abo_num = 0;
int N, K;

double get_Expect(int ridip)
{
	int cur = 0;
	double res = 0.0, prev = 0.0;
	while (cur <= ridip)
	{
		int k = upper_bound(val, val + N, prev) - val;
		double t = 0;
		for (int i = k; i < N; i++)
			t += val[i];
		t /= N;
		res = prev * k / N + t;
		prev = res;
		cur++;
	}
	return res;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0, cur = 0;
	cin >> kasenum;

	while (++cur <= kasenum)
	{
		avg = 0.0;
		cin >> N >> K;
		for (int i = 0; i < N; i++)
		{
			cin >> val[i];
			avg += val[i];
		}
		avg /= N;
		sort(val, val + int(N));

		double res = get_Expect(K);
		//cout << "Case #" << cur << ": " << res << endl;
		printf("Case #%d: %.6f\n", cur, res);
	}

	return 0;
}
