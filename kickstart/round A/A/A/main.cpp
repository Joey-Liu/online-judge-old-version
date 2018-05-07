#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;
LL l_num;

LL work(const string num, int ind)
{
	if (ind < 0)
		return 0;

	LL La, Lb;

	string r1 = num;
	r1[ind] -= 1;
	for (int i = ind + 1; i < r1.size(); i++)
		r1[i] = '8';

	stringstream ss1(r1);
	ss1 >> La;

	if ('9' == num[ind])
		return abs(l_num - La);

	string r2 = num;
	r2[ind] += 1;
	for (int i = ind + 1; i < r2.size(); i++)
		r2[i] = '0';

	stringstream ss2(r2);
	ss2 >> Lb;

	return min(abs(l_num - La), abs(l_num - Lb));
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	int kasenum = 0, cur = 0;
	cin >> kasenum;
	LL res = 0;
	string num;

	while (++cur <= kasenum)
	{
		res = 0;
		cin >> num;
		int ind = -1;
		for (int i = 0; i < num.size(); i++)
		{
			if ((num[i] - '0') % 2)
			{
				ind = i;
				break;
			}
		}//for
		stringstream ss(num);
		ss >> l_num;
		res = work(num, ind);
		cout << "Case #" << cur << ": " << res << endl;
	}

	return 0;
}