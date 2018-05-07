//#include <iostream>
//#include <string>
//#include <string.h>
//#include <vector>
//
//using namespace std;
//
//int length;
//
//bool check(string str)			//是回文 true
//{
//	int len = str.size();
//	for (int i = 0; i < len / 2; i++)
//	{
//		if (str[i] != str[len - i - 1])
//			return false;
//	}
//
//	return true;
//}
//
//vector<int > vi;
//int main()
//{
//	string s,ans;
//	while (cin >> length)
//	{
//		cin >> s;
//		vi.clear();
//
//		for (int i = 0; i < s.size(); i++)
//		{
//			if ('?' == s[i])
//				vi.push_back(i);
//		}
//		if (vi.size() == 0)
//		{
//			cout << "QwQ" << endl;
//			continue;
//		}
//
//		for (int ch = 'a'; ch <= 'z'; ch++)
//		{
//			ans = s;
//			for (int i = 0; i < vi.size(); i++)
//			{
//
//			}
//		}
//	}
//}



#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int length;
string str,ans;
vector<int > vi;

bool check(string str)			//回文 true
{
	int len = str.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - i - 1])
			return false;
	}

	return true;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> length )
	{
		vi.clear();
		cin >> str;
		for (int i = 0; i < str.size(); i++)
		{
			if ('?' == str[i])
				vi.push_back(i);
		}

		if (0 == vi.size())
		{
			if (check(str))
				cout << "QwQ" << endl;
			else
				cout << str << endl;
			continue;
		}

		for (int i = 0; i < vi.size(); i++)
			str[vi[i]] = 'a';
		
		if (check(str))
		{
			//知道 ？ 在中间时是一个点，但忘了加上 判断str长度是不是 双数
			if ( (vi[vi.size() - 1] == str.size() / 2) && (0 != length % 2) && vi.size() != 1)
			{
				str[vi[vi.size() - 2]] = 'b';
				cout << str << endl;
				continue;
			}

			str[vi[vi.size() - 1]] = 'b';
			if (check(str))
			{
				cout << "QwQ" << endl;
				continue;
			}
			else
				cout << str << endl;
			//bool flag = false;
			//for (int i = vi.size() - 1; i >= 0; i--)
			//{
			//	if (vi[i] != length / 2 || 0 == length % 2)
			//	{
			//		str[vi[i] ] = 'b';
			//		flag = true;
			//		break;
			//	}
			//}//for

			//if (flag)
			//	cout << str << endl;
			//else
			//	cout << "QwQ" << endl;
		}
		else
			cout << str << endl;
	}

	return 0;
}

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

bool hasFound = false;
vector<int > vi;
string str;
int length;

bool check() //回文 true
{
	int len = str.size();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
			return false;
	}

	return true;
}

void dfs(int step)
{
	if (hasFound || step >= vi.size())
		return;

	for (int i = 'a'; i <= 'z'; i++)
	{
		str[vi[step] ] = i;
		if (step != vi.size() - 1)
		{
			dfs(step + 1);
			if (hasFound)
				return;
		}
		else
		{
			if (!check())
			{
				hasFound = true;
				return;
			}
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> length)
	{
		hasFound = false;
		vi.clear();
		cin >> str;
		
		for (int i = 0; i < length; i++)
		{
			if ('?' == str[i])
				vi.push_back(i);
		}

		if (0 == vi.size())
		{
			if (check())
				cout << "QwQ" << endl;
			else
				cout << str << endl;
			continue;
		}

		dfs(0);

		if (hasFound)
			cout << str << endl;
		else
			cout << "QwQ" << endl;

	}
	return 0;
}