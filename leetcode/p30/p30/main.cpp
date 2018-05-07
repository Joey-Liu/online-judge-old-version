#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void getNext(string p, int next[])
{
	next[0] = -1;
	int j = 0, k = -1, pLen = p.size();
	while (j < pLen - 1)
	{
		if (k == -1 || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}//while 
}

int kmp(string s, string p)
{
	int sLen = s.size();
	int pLen = p.size();
	int *next = new int[pLen];
	getNext(p, next);

	int i = 0, j = 0;
	while (i < sLen && j < pLen)
	{
		if (j == -1 || s[i] == p[j])
		{
			j++;
			i++;
		}
		else
			j = next[j];
	}
	delete next;
	if (j == pLen)
		return i - j;
	return -1;
}

void dfs(int N, int layer, vector<int> vi, vector<vector<int> > & vvi)
{
	if (layer == N)
	{
		vvi.push_back(vi);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		for (int j = 0; j < vi.size(); j++)
		{
			if (vi[j] == i)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			continue;
		vector<int> t = vi;
		vi.push_back(i);
		dfs(N, layer + 1, vi, vvi);
		vi = t;
	}//for int i
}

vector<int> findSubstr(string s, string p)
{
	int sLen = s.size(), pLen = p.size();
	vector<int> vi;

	for (int i = 0; i <= sLen - pLen; i++)
	{
		bool flag = true;
		for (int j = 0; j < pLen; j++)
		{
			if (s[i + j] != p[j])
			{
				flag = false;
				break;
			}
		}//for int j
		if (flag)
			vi.push_back(i);
	}
	return vi;
}

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words)
	{
		vector<vector<int> > vvi;
		vector<int> vit, v;
		dfs(words.size(), 0, vit, vvi);
		string str = s;
		for (int i = 0; i < vvi.size(); i++)
		{
			string p = "";
			for (int j = 0; j < vvi[i].size(); j++)
				p += words[vvi[i][j]];
			vit = findSubstr(s, p);
			for (int i = 0; i < vit.size(); i++)
				v.push_back(vit[i]);
		}

		sort(v.begin(), v.end());
		vector<int>::iterator it = unique(v.begin(), v.end());
		v.resize(it - v.begin());
		return v;
	}
};

int main()
{
	string s = "barfoothefoobarman";
	vector<string> vs = { "foo", "bar" };
	Solution sol;
	sol.findSubstring(s, vs);
	return 0;
}