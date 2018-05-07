#include <iostream>
#include <stdlib.h>
#include <vector>
#include <memory.h>

using namespace std;
typedef long long LL;
const int maxn = 100000 + 50;
LL X[maxn], Y[maxn], N;

bool check(int a, int b, int c)
{
	return (X[a] - X[b]) * (Y[c] - Y[b]) == (X[c] - X[b]) * (Y[a] - Y[b]);
}

bool check_all(bool valid[])
{
	vector<int> vi;
	int cnt = 0;
	for (int i = 0; i < N; i++)
		if (!valid[i])
			vi.push_back(i);
	if (vi.size() <= 2)
		return true;

	for (int i = 2; i < vi.size(); i++)
		if (!check(vi[0], vi[1], vi[i]))
			return false;
	return true;
}

bool work()
{
	bool valid[maxn], zi_valid[maxn], oi_valid[maxn];
	memset(valid, false, sizeof(valid));
	memset(zi_valid, false, sizeof(zi_valid));
	memset(oi_valid, false, sizeof(oi_valid));

	valid[0] = valid[1] = true;
	for (LL i = 0; i < N; i++)
		if (check(0, 1, i))
			valid[i] = true;

	if (check_all(valid))
		return true;
	int ind = 0;
	for (int i = 0; i < N; i++)
	{
		if (!valid[i])
		{
			ind = i;
			break;
		}
	}

	zi_valid[0] = zi_valid[ind] = true;
	for (LL i = 0; i < N; i++)
		if (check(0, ind, i))
			zi_valid[i] = true;

	if (check_all(zi_valid))
		return true;

	oi_valid[1] = oi_valid[ind] = true;
	for (LL i = 0; i < N; i++)
		if (check(1, ind, i))
			oi_valid[i] = true;
	if (check_all(oi_valid))
		return true;
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (LL i = 0; i < N; i++)
		cin >> X[i] >> Y[i];
	if (N <= 4)
	{
		cout << "YES" << endl;
		return 0;
	}
	if (work())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;

}