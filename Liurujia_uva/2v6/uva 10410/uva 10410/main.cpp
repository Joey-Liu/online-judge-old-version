#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 1000 + 10;
vector<int> children[maxn];
int N, pos[maxn];

int main()
{
	while (cin >> N && N)
	{
		for (int i = 0; i < N; i++)
		{
			int t;
			cin >> t;
			pos[t] = i;
		}

		for (int i = 0; i < N; i++)
			children[i].clear();



		for (int i = 1; i < N;i++)
		{
			int t
		}

	}//while

}