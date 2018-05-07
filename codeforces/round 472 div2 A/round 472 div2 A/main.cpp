#include <iostream>
#include <memory.h>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;

string str;
int N;

bool work()
{
	if (str[0] == '?' || str[N - 1] == '?')
		return true;
	else
	{
		for (int i = 0; i < N - 1; i++)
		{
			if (str[i] == '?' && str[i] == str[i + 1])
			{
				return true;
			}
		}

		for (int i = 1; i < N - 1; i++)
		{
			if (str[i] == '?' && str[i - 1] == str[i + 1])
				return true;
		}
	}
	return false;
}

int main() 
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	bool flag = true;
	cin >> N >> str;

	for (int i = 0; i < N - 1; i++)
	{
		if (str[i] != '?' && str[i] == str[i + 1])
		{
			flag = false;
			break;
		}
	}

	if (!flag)
		cout << "No" << endl;
	else
	{
		if (work())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}