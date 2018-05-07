#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int element_num, ques_num, target, tmp, kasenum = 0;
	vector<int> marbles;

	while (cin >> element_num >> ques_num && element_num && ques_num)
	{
		marbles.clear();
		for (int i = 0; i < element_num; i++)
		{
			cin >> tmp;
			marbles.push_back(tmp);
		}
		
		sort(marbles.begin(), marbles.end());
		cout << "CASE# " << ++kasenum << ":" << endl;

		for (int i = 0; i < ques_num; i++)
		{
			cin >> target;
			int position = lower_bound(marbles.begin(), marbles.end(), target) - marbles.begin();
			if (position >= marbles.size() || marbles[position] != target)
				cout << target << " not found" << endl;
			else
				cout << target << " found at " << position + 1 << endl;
		}
	}
	return 0;
}