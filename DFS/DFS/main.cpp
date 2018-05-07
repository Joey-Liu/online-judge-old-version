#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 9;

int ans[maxn];
bool visited[maxn];

void work(int layer)
{
	if (layer >= maxn)
	{
		for (int i = 0; i < maxn; i++)
			cout << ans[i];
		cout << endl;
	}
	for (int i = 0; i < maxn; i++)
	{
		if (!visited[i])
		{
			ans[layer] = i;
			visited[i] = true;
			work(layer + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	memset(visited, false, sizeof(visited));
	work(0);
	system("pause");
}