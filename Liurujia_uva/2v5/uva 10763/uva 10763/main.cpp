#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <algorithm>

using namespace std;

int N;
map<pair<int, int>, int> student;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> N && N)
	{
		student.clear();
		int location, target;
		for (int i = 0; i < N; i++)
		{
			cin >> location >> target;
			pair<int, int> stu(location, target);
			pair<int, int> rev_stu(target, location);
			if (student.count(rev_stu))
				student[rev_stu]--;
			else
			{
				if (!student.count(stu))
					student[stu] = 0;
				student[stu]++;
			}
		}
		bool flag = true;
		for (map<pair<int, int>, int>::iterator it = student.begin(); it != student.end(); it++)
		{
			if (it->second != 0)
			{
				flag = false;
				break;
			}
		}
		string res = flag ? "YES" : "NO";
		cout << res << endl;
	}//while
	return 0;
}