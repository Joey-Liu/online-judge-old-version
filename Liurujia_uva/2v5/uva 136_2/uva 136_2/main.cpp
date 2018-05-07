#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>

typedef long long LL;
using namespace std;


set<LL> visited;
priority_queue<LL, vector<LL>, greater<LL> > ugly_num;

int coff[] = { 2, 3, 5 };
int main()
{
	visited.insert(1);
	ugly_num.push(1);
	int index = 1;
	LL t;
	
	while (true)
	{
		t = ugly_num.top();
		ugly_num.pop();
		if (1500 == index)
			break;

		for (int i = 0; i < 3; i++)
		{
			LL ta = t * coff[i];
			if (!visited.count(ta))
			{
				visited.insert(ta);
				ugly_num.push(ta);
			}
		}
		index++;
	}//while true
	cout << t << endl;
	cin >> t;
	return 0;
}