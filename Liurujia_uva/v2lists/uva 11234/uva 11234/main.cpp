#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
const int maxn = 10000 + 100;

char expre[maxn];
vector<int> sons[maxn];
int parent[maxn];
stack<int> st;
queue<int> que;
int length = 0;
char ans[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum;
	cin >> kasenum;
	while (kasenum--)
	{
		cin >> expre;
		length = strlen(expre);
		while (!st.empty())
			st.pop();
		memset(parent, -1, sizeof(parent));
		for (int i = 0; i < length; i++)
			sons[i].clear();

		for (int i = 0; i < length; i++)
		{
			if (islower(expre[i]))
				st.push(i);
			else
			{
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();

				sons[i].push_back(b);
				sons[i].push_back(a);
				parent[a] = i;
				parent[b] = i;
				st.push(i);
			}//else
		}//for

		int root = 0;
		for (int i = 0; i < length; i++)
		{
			if (-1 == parent[i])
			{
				root = i;
				break;
			}
		}

		int index = 0;
		while (!que.empty())
			que.pop();
		que.push(root);
		while (!que.empty())
		{
			int n = que.front();
			que.pop();
			ans[index++] = expre[n];
	
			for (int i = 0; i < sons[n].size(); i++)
				que.push(sons[n].at(i));
		}
		for (index--; index >= 0; index--)
			printf("%c", ans[index]);
		printf("\n");
	}//while

	return 0;
}