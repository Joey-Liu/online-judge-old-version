#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int my_next(int n, int k)
{
	stringstream ss;
	ss << (long long)k * k;
	string s = ss.str();
	if (s.length() > n)
		s = s.substr(0, n);
	int ans;
	stringstream ss2(s);
	ss2 >> ans;
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	cin >> casenum;
	while (casenum--)
	{
		int n, k;
		cin >> n >> k;
		set<int> s;
		int ans = k;
		while (!s.count(k))
		{
			s.insert(k);
			k = my_next(n, k);
			if (ans < k)
				ans = k;
		}
		cout << ans << endl;
	}
	return 0;
}