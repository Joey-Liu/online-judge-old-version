#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 200 + 30;

string str[maxn];
int N, root;
map<pair<int, int>, vector<pair<int, int> > > children;


void build_tree(int r, int c)
{
	vector<pair<int, int> > vi;
	pair<int, int> pa(r, c);
	//children[pa] = vi;

	int idx = c, iny = c;
	if (r + 1 < N && '|' == str[r + 1][c])
	{
		while (idx >= 0 && str[r + 2][idx] == '-')
			idx--;
		while (iny < str[r + 2].size() && str[r + 2][iny] == '-')
			iny++;

		for (int i = idx + 1; i < min(iny, (int)str[r + 3].size()); i++)
		{
			if (!isspace(str[r + 3][i]))
			{
				pair<int, int> t(r + 3, i);
				vi.push_back(t);
				build_tree(r + 3, i);
			}
		}//for
	}
	children[pa] = vi;
}

void print_tree(int r, int c)
{
	pair<int, int> pa(r, c);
	printf("%c(", str[r][c]);
	for (int i = 0; i < children[pa].size(); i++)
	{
		pair<int, int> ptmp = children[pa][i];
		print_tree(ptmp.first, ptmp.second);
	}
	printf(")");
}

void work()
{
	for (int i = 0; i < str[0].size(); i++)
	{
		if (!isspace(str[0][i]))
		{
			root = i;
			break;
		}
	}
	if (N)
	{
		build_tree(0, root);
		printf("(");
		print_tree(0, root);
		printf(")\n");
	}
	else
		printf("()\n");
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	getchar();
	while (kasenum--)
	{
		children.clear();
		N = 0;
		while (getline(cin, str[N]) && '#' != str[N][0])
			N++;
		work();
	}
	return 0;
}