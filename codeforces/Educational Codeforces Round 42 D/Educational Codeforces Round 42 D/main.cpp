#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <memory.h>

using namespace std;
const int maxn = 150000 + 50;
bool exist[maxn];

typedef long long LL;

map<LL, vector<LL> > miv;
int N;

void work(vector<LL> & vi) {
	while (true) {
		LL ind = -1;
		for (map<LL, vector<LL> >::iterator it = miv.begin(); it != miv.end(); it++) {
			if (it->second.size() >= 2) {
				ind = it->first;
				break;
			}
		}
		if (ind < 0)
			break;

		LL fi = miv[ind][0], se = miv[ind][1];

		exist[fi] = false;
		miv[ind].erase(miv[ind].begin());
		miv[ind].erase(miv[ind].begin());
		miv[ind * 2].push_back(se);
		vi[se] = ind * 2L;
		sort(miv[ind * 2].begin(), miv[ind * 2].end());
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
		LL t = 0;
		cin >> t;
		vi[i] = t;
		miv[t].push_back(i);
	}
	memset(exist, true, sizeof(exist));
	work(vi);
	
	int i = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if(exist[i])
			cnt++;
	}
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
		if(exist[i])
			cout << " " << vi[i];
	}
	cout << endl;
	return 0;
}