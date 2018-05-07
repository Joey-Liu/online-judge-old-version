#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
const int maxn = 100000 + 100;
int casenum;
int size;
int num[maxn];
int ans = 0;
void work(int & lp,int & rp)			//¸øans£¬ lp,rp¸³Öµ
{
	ans = num[0];
	int pre = ans;

	for (int i = 1; i < size; i++)
	{
		if (pre > 0)
			pre += num[i];
		else
			pre = num[i];
		if (pre > ans)
		{
			ans = pre;
			rp = i;
		}
	}

	int tmp = 0;
	for (int i = rp; i >= 0; i--)
	{
		tmp += num[i];
		if (tmp == ans)
			lp = i;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cnt = 1;
	cin >> casenum;
	while (casenum--)
	{
		if (1 != cnt)
			cout << endl;
		cin >> size;
		for (int i = 0; i < size; i++)
			cin >> num[i];
		int lp = 0, rp = 0;
		work(lp, rp);
		cout << "Case " << cnt++ << ":" << endl;
		cout << ans << " " << lp + 1 << " " << rp + 1 << endl;
	}
	return 0;
}