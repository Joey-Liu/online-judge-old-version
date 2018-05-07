#define LOCAL

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 25 + 10;
vector<int> block[maxn];
string verb, prep;
int n, first, second, blockNum[maxn];

void removeAbove(int target)
{
	int bn = blockNum[target], index;
	for (int i = 0; i < block[bn].size(); i++)
	{
		if (target != block[bn][i])
			continue;
		else 
		{ index = i; break; }
	}

	for (int i = index + 1; i < block[bn].size(); i++)
	{
		int tmp = block[bn][i];
		blockNum[tmp] = tmp;
		block[tmp].push_back(tmp);
	}

	block[bn].resize(index + 1);
}

void pileAbove(int source, int target)
{
	int bs = blockNum[source];
	int bta = blockNum[target];

	int sind, taind;
	for (int i = 0; i < block[bs].size(); i++)
	{
		if (block[bs][i] != source)
			continue;
		else
		{
			sind = i;
			break;
		}
	}//for int i

	for (int i = sind; i < block[bs].size(); i++)
	{
		int tmp = block[bs][i];
		blockNum[tmp] = bta;
		block[bta].push_back(tmp);
	}
	block[bs].resize(sind);
}


int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		block[i].push_back(i);
		blockNum[i] = i;
	}

	while (cin >> verb)
	{
		if (verb[0] == 'q')
			break;
		cin >> first >> prep >> second;
		
		if (blockNum[first] == blockNum[second])
			continue;
		
		if (verb[0] == 'm')
			removeAbove(first);
		if (prep[1] == 'n')
			removeAbove(second);
		pileAbove(first, second);
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << ":";
		for (int j = 0; j < block[i].size(); j++)
			cout << " " << block[i][j];
		cout << endl;
	}
	return 0;
}