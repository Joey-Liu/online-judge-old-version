#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int maxn = 500 + 50;
string tab[maxn];
int H, W;

int cnt[maxn][maxn];

bool in_matrix(int r, int c) {
	if (r < 0 || r >= H || c < 0 || c >= W)
		return false;
	return true;
}

bool exist(int r, int c, vector<pair<int, int> > & vp)
{
	for (int i = 0; i < vp.size(); i++) {
		int a = vp[i].first, b = vp[i].second;
		if (r == a && c == b)
			return true;
	}
	return false;
}

bool walk(int r, int c, vector<pair<int, int> > & vp)
{
	if (!in_matrix(r, c) || 1 == cnt[r][c]) {
		for (int i = 0; i < vp.size(); i++) {
			int a = vp[i].first, b = vp[i].second;
			cnt[a][b] = 1;
		}
		return true;
	}

	if (-1 == cnt[r][c] || exist(r, c, vp)) {
		for (int i = 0; i < vp.size(); i++) {
			int a = vp[i].first, b = vp[i].second;
			cnt[a][b] = -1;
		}
		return false;
	}
	
	vp.push_back(pair<int, int>(r, c));
	if ('U' == tab[r][c]) {
		walk(r - 1, c, vp);
	}
	else if ('R' == tab[r][c]){
		walk(r, c + 1, vp);
	}
	else if ('D' == tab[r][c]) {
		walk(r + 1, c, vp);
	}
	else {
		walk(r, c - 1, vp);
	}
}

int work()
{
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (0 == cnt[i][j]) {
				vector<pair<int, int> > vp;
				walk(i, j, vp);
			}
		}
	}

	int res = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (1 == cnt[i][j]) {
				res++;
			}
		}
	}
	return res;
}

int main() {
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		cin >> tab[i];
	}
	memset(cnt, 0, sizeof(cnt));
	int res = work();
	cout << res << endl;

	return 0;
}