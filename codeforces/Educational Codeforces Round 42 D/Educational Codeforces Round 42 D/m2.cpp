#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 150000 + 50;
bool exist[maxn];

typedef long long LL;
map<LL, set<int> > mis;
int N;

void work(vector<LL> & vi, int & cnt) {
	LL nu;
	for (map<LL, set<int>>::iterator it = mis.begin(); it != mis.end(); it++) {
		while (it->second.size() >= 2) {
			nu = it->first;
			set<int>::iterator it = mis[nu].begin();
			int fi = *it;
			mis[nu].erase(it);
			it = mis[nu].begin();
			int se = *it;
			mis[nu].erase(it);
			exist[fi] = false;
			cnt--;
			mis[nu * 2].insert(se);
			vi[se] = nu * 2L;
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	vector<LL> vi(N, 0);
	for (int i = 0; i < N; i++) {
		LL t;
		cin >> t;
		vi[i] = t;
		mis[t].insert(i);
	}
	int cnt = N, i;
	memset(exist, true, sizeof(exist));
	work(vi, cnt);
	cout << cnt << endl;
	for (i = 0; i < vi.size(); i++) {
		if (exist[i])
		{
			cout << vi[i];
			break;
		}
	}

	i += 1;
	for (; i < vi.size(); i++) {
		if (exist[i])
			cout << " " << vi[i];
	}
	cout << endl;
	return 0;
}