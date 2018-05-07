#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>
#include <memory.h>
#include <stack>

using namespace std;

struct Toy
{
	int id;
	int size;
};
const int maxn = 50000 + 30;
int stPoint = 0, temp = 0, toys[maxn], parent[maxn], toyCnt = 0;
string str;
bool flag = true;
stack<Toy> toyStack;
Toy toybp[maxn];

void check()
{
	while (!toyStack.empty())
		toyStack.pop();

	for (int i = 0; i < stPoint; i++)
	{
		if (toys[i] < 0)
		{
			Toy t;
			t.id = toyCnt++;
			t.size = -toys[i];
			toybp[t.id] = t;
			toyStack.push(t);
		}
		else
		{
			if (!toyStack.empty() && toyStack.top().size == toys[i])
			{
				Toy t = toyStack.top();
				toyStack.pop();
				if (!toyStack.empty())
					parent[t.id] = toyStack.top().id;
				else
					parent[t.id] = -13;
			}
			else
				flag = false;
		}//else
	}

	if (!toyStack.empty())
		flag = false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (getline(cin, str))
	{
		stringstream ss(str);
		stPoint = 0;
		flag = true;
		memset(parent, -1, sizeof(parent));
		toyCnt = 0;

		while (ss >> temp)
			toys[stPoint++] = temp;
		check();
		if (flag)
		{
			for (int i = 0; i < toyCnt; i++)
			{
				int parIndex = parent[i];
				if (parIndex == -13)
					continue;
				else
				{
					int sum = 0;
					for (int j = 0; j < toyCnt; j++)
					{
						if (parent[j] == parIndex)
							sum += toybp[j].size;
					}
					if (sum >= toybp[parIndex].size)
						flag = false;
				}//else
			}//for
		}
		printf("%s\n", flag ? ":-) Matrioshka!" : ":-( Try again.");
	}//while
	return 0;
}