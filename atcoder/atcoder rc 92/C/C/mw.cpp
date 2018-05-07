#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
const int N = 1001;

int num, res;

struct Node
{
	int x, y, flag;
	Node(int a = -1, int b = -1, int f = 0)
	{
		x = a;
		y = b;
		flag = f;
	}
};

bool cmp(Node a, Node b)
{
	return a.x < b.x;
}

vector<Node> vn;

void work()
{
	multiset<int> ms;
	for (int i = 0; i < vn.size(); i++)
	{
		if (!vn[i].flag)
			ms.insert(vn[i].y);
		else
		{
			int k = -1;
			for (int j = vn[i].y - 1; j >= 0; j--)
			{
				if (ms.count(j))
				{
					k = j;
					break;
				}
			}
			if (k >= 0)
			{
				ms.erase(k);
				res++;
			}
		}
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &num);
	for(int i = 0;i < 2 * num;i++)
	{
		int a, b, flag = 0;
		scanf("%d%d", &a, &b);

		if (i >= num)
			flag = 1;
		vn.push_back(Node(a, b, flag));
	}

	multiset<int> msi;


	sort(vn.begin(), vn.end(), cmp);
	work();

	printf("%d\n", res);
	return 0;
}