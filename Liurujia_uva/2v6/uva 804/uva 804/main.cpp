#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

const int maxn = 150;
int token[maxn];

struct Trans
{
	map<int, int> sour;
	map<int, int> dest;
};

vector<Trans> vt;
int NP, NT, NF;

bool available(Trans tran)
{
	for (auto it = tran.sour.begin(); it != tran.sour.end(); it++)
	{
		if (token[it->first] < it->second)
			return false;
	}
	return true;
}

void apply(Trans tran)
{
	for (auto it = tran.sour.begin(); it != tran.sour.end(); it++)
		token[it->first] -= it->second;

	for (auto it = tran.dest.begin(); it != tran.dest.end(); it++)
		token[it->first] += it->second;
}

bool work()
{
	bool flag = false;
	for (int i = 0; i < vt.size(); i++)
	{
		flag = available(vt[i]);
		if (flag)
		{
			apply(vt[i]);
			flag = true;
			break;
		}
	}
	return flag;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum = 0;
	while (cin >> NP && NP)
	{
		memset(token, 0, sizeof(token));
		vt.clear();
		for (int i = 0; i < NP; i++)
			cin >> token[i + 1];

		cin >> NT;
		for (int i = 0; i < NT; i++)
		{
			Trans tran;
			int tmp;
			while (cin >> tmp && tmp)
			{
				if (tmp < 0)
					tran.sour[-tmp]++;
				else
					tran.dest[tmp]++;
			}
			vt.push_back(tran);
		}//for int i
		cin >> NF;

		bool flag = true;
		int idx = 0;
		for (int i = 0; i < NF; i++)
		{
			flag = work();
			if (!flag)
				break;
			idx++;
		}
		
		cout << "Case " << ++kasenum;
		if (flag)
			cout << ": still live after " << idx << " transitions\n";
		else
			cout << ": dead after " << idx << " transitions\n";
		cout << "Places with tokens:";
		
		for (int i = 0; i <= NP; i++)
		{
			if (!token[i])
				continue;
			cout << " " << i << " (" << token[i] << ")";
		}
		cout << "\n\n";
	}//while cin>>NP
	return 0;
}