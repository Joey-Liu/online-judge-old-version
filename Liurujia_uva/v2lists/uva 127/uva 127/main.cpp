#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stack>

using namespace std;
const int maxn = 60;
stack<string> pokerPile[maxn];
string str;

bool matches(string s1, string s2)
{
	if (s1[0] == s2[0] || s1[1] == s2[1])
		return true;
	return false;
}

int moveCard(int index)
{
	if (!index)
		return -1;
	int cnt = 0, target = index;
	while (target > 0)
	{
		target--;
		if (!pokerPile[target].empty())
			cnt++;
		if (cnt >= 3)
			break;
	}

	if (target >= 0 && cnt >= 3)
	{
		if (matches(pokerPile[target].top(), pokerPile[index].top()))
			return target;
	}

	target = index;
	while (target > 0)
	{
		target--;
		if (!pokerPile[target].empty())
			break;
	}
	if (target >= 0 && !pokerPile[target].empty())
	{
		if (matches(pokerPile[target].top(), pokerPile[index].top()))
			return target;
	}
	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> str)
	{
		if (str[0] == '#')
			break;
		for (int i = 0; i < maxn; i++)
		{
			while (!pokerPile[i].empty())
				pokerPile[i].pop();
		}//for

		pokerPile[0].push(str);
		for (int i = 1; i < 52; i++)
		{
			cin >> str;
			pokerPile[i].push(str);
		}

		while (true)
		{
			bool flag = false;
			for (int i = 1; i < 52;)
			{
				if (pokerPile[i].empty())
				{
					i++;
					continue;
				}
				int res = moveCard(i);
				if (res >= 0)
				{
					flag = true;
					string stemp = pokerPile[i].top();
					pokerPile[i].pop();
					pokerPile[res].push(stemp);
					i = res;
				}
				else
					i++;
			}//for 
			if (!flag)
				break;
		}
		int cnt = 0;
		for (int i = 0; i < 52; i++)
		{
			if (!pokerPile[i].empty())
				cnt++;
		}
		cout << cnt << (cnt > 1 ? " piles " : " pile ");
		cout << "remaining:";
		for (int i = 0; i < 52; i++)
		{
			if (!pokerPile[i].empty())
				cout << " " << pokerPile[i].size();
		}
		cout << endl;
	}//while
	return 0;
}