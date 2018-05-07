#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

string str;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> str;

	set<int> zers, ones;
	vector<vector<int> > seqs;

	for (int i = 0; i < str.size(); i++)
	{
		if ('1' == str[i])
			ones.insert(i);
		else
			zers.insert(i);
	}

	bool flag = true;
	if (zers.empty())
		flag = false;

	while(!zers.empty())
	{
		auto zit = zers.begin();
		int z_pos = *zit;
		int o_pos;
		set<int>::iterator o_pit;

		vector<int> tmp;
		while(true)
		{
			tmp.push_back(z_pos);
			zers.erase(zit);

			//o_pit = lower_bound(ones.begin(), ones.end(), z_pos);
			o_pit = ones.lower_bound(z_pos);
			if (o_pit == ones.end())
				break;
			o_pos = *o_pit;
			tmp.push_back(o_pos);
			ones.erase(o_pit);

			//zit = lower_bound(zers.begin(), zers.end(), o_pos);
			zit = zers.lower_bound(o_pos);

			if (zit == zers.end())
			{
				flag = false;
				break;
			}
			z_pos = *zit;
		}
		if(flag)
			seqs.push_back(tmp);
		else
			break;
	}

	if (!ones.empty())
		flag = false;

	if (!flag)
		cout << -1 << endl;
	else
	{
		cout << seqs.size() << endl;
		for (int i = 0; i < seqs.size(); i++)
		{
			vector<int> & vi = seqs[i];
			cout << vi.size();
			for (int i = 0; i < vi.size(); i++)
				cout << " " << vi[i] + 1;
			cout <<"\n";
		}
	}
	return 0;
}