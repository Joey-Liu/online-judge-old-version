#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;
int N;

vector<string> pec[4];

int work(int st, vector<int> & perm)
{
	int re1 = 0, re2 = 0, t = st;
	for (int i = 0; i < N; i++) {
		string str = pec[perm[0]][i] + pec[perm[1]][i];
		for (int j = 0; j < N * 2; j++) {
			int cur = str[j] - '0';
			if (st != cur)
				re1++;
			st = 1 - st;
		}
		st = 1 - st;
	}
	st = 1 - t;
	for (int i = 0; i < N; i++) {
		string str = pec[perm[2]][i] + pec[perm[3]][i];
		for (int j = 0; j < N * 2; j++) {
			int cur = str[j] - '0';
			if (st != cur)
				re2++;
			st = 1 - st;
		}
		st = 1 - st;
	}
	return re1 + re2;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	string str;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < N; j++) {
			cin >> str;
			pec[i].push_back(str);
		}
	}

	vector<int> perm{ 0, 1, 2, 3 };
	int mini = 0x7fffffff;
	do {
		int r1 = work(0, perm);
		int r2 = work(1, perm);
		int t = min(r1, r2);
		mini = min(mini, t);
	} while (next_permutation(perm.begin(), perm.end()));
	cout << mini << endl;
	return 0;
}