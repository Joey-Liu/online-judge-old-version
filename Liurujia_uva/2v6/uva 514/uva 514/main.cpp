#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stack>

using namespace std;
const int maxn = 1000 + 10;

int target[maxn], N;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N && N)
	{
		while (true)
		{
			cin >> target[0];
			if (!target[0])
				break;
			for (int i = 1; i < N; i++)
				cin >> target[i];

			stack<int> s;
			bool flag = true;
			int x = 1, pos = 0;
			while (pos < N)
			{
				if (target[pos] == x)
				{
					pos++;
					x++;
				}
				else if (!s.empty() && s.top() == target[pos])
				{
					s.pop();
					pos++;
				}
				else if (x < target[pos])
				{
					s.push(x);
					x++;
				}
				else
				{
					flag = false;
					break;
				}
			}//while pos
			string res = flag ? "Yes" : "No";
			cout << res << endl;
		}//while true
		cout << endl;
	}//while cin
	return 0;
}