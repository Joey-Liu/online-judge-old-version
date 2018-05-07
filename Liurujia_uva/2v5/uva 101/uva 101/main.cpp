#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
const int maxn = 25 + 5;
string s1, s2;
int a, b, block_num;

vector<int> block[maxn];

void find_block(int ta, int & p, int & height)
{
	for (p = 0; p < block_num; p++)
		for (height = 0; height < block[p].size(); height++)
			if (block[p][height] == ta)
				return;
}

void clear_block(int p, int h)
{
	for (int i = block[p].size() - 1; i > h; i--)
	{
		int n = block[p][i];
		block[n].push_back(n);
	}
	block[p].resize(h + 1);
}

void put_on(int pa, int height, int pb)
{
	int h = height;
	for (; height < block[pa].size(); height++)
	{
		int n = block[pa][height];
		block[pb].push_back(n);
	}
	block[pa].resize(h);
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> block_num;
	for (int i = 0; i < block_num; i++)
		block[i].push_back(i);
	
	while (cin >> s1 && 'q' != s1[0])
	{
		cin >> a >> s2 >> b;
		int pa, pb, ha, hb;
		find_block(a, pa, ha);
		find_block(b, pb, hb);

		if (pa == pb)
			continue;
		if ("move" == s1)
			clear_block(pa, ha);
		if ("onto" == s2)
			clear_block(pb, hb);
		put_on(pa, ha, pb);
	}

	for (int i = 0; i < block_num; i++)
	{
		cout << i << ":";
		for (int j = 0; j < block[i].size(); j++)
		{
			cout << " " << block[i][j];
		}//for int j
		cout << endl;
	}//for int i
	return 0;
}