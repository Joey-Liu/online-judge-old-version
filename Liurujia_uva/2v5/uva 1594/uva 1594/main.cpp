#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <math.h>

using namespace std;
int n;

vector<int> ducci;
set<vector<int> > visited;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		visited.clear();
		ducci.clear();

		cin >> n;
		int x;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			ducci.push_back(x);
		}
		visited.insert(ducci);
		
		bool flag_loop = false, flag_zero = true;
		for(int i = 0;i < 1e3;i++)
		{
			flag_zero = true;
			vector<int> vid;
			for(int j = 0; j < n; j++)
				vid.push_back(abs(ducci[j%n] - ducci[(j + 1) % n]));
			
			for (int j = 0; j < n; j++)
			{
				if (0 != vid[j])
				{
					flag_zero = false;
					break;
				}
			}
			if (flag_zero)
				break;

			if (visited.count(vid))
			{
				flag_loop = true;
				break;
			}
			visited.insert(vid);
			ducci = vid;
		}
		if (flag_zero)
			cout << "ZERO" << endl;
		else
			cout << "LOOP" << endl;
	}//while
	return 0;
}