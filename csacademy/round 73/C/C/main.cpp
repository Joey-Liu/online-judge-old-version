#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;

const int maxn = 100000 + 100;

int p1[maxn], p2[maxn], N;
vector<int> chi1[maxn], chi2[maxn];

bool isIso(int a, int b)
{
	if (!chi1[a].size() && !chi2[b].size())
		return true;
	
	if (chi1[a].size() != chi2[b].size())
		return false;

	if (1 == chi1[a].size())
		return isIso(chi1[a][0], chi2[b][0]);
	else
	{
		bool fag1 = (isIso(chi1[a][0], chi2[b][0]) && isIso(chi1[a][1], chi2[b][1]));
		bool fag2 = (isIso(chi1[a][1], chi2[b][0]) && isIso(chi1[a][0], chi2[b][1]));
		return (fag1 || fag2);
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	cin >> kasenum;
	while (kasenum--)
	{
		memset(p1, 0, sizeof(p1));
		memset(p2, 0, sizeof(p2));
		int r1, r2;
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> p1[i];
		for (int i = 1; i <= N; i++)
			cin >> p2[i];
				
		for (int i = 0; i <= N; i++)
		{
			chi1[i].clear();
			chi2[i].clear();
		}

		for (int i = 1; i <= N; i++)
		{
			if (!p1[i])
				r1 = i;
			if (!p2[i])
				r2 = i;
			chi1[p1[i]].push_back(i);
			chi2[p2[i]].push_back(i);
		}


		bool flag = isIso(r1, r2);
		if (flag)
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}