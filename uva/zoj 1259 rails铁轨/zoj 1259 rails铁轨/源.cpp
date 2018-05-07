#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <algorithm>

using namespace std;
const int maxn = 1000 + 100;
int N;
int brr[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	stack<int> rails;
	bool first = true;
	while (1 == scanf("%d", &N) && (0 != N))
	{
		if (!first)
			printf("\n\n");
		first = false;
		bool fff = true;

		while (1 == scanf("%d", &brr[1]))
		{
			bool flag = true;
			while (!rails.empty())
				rails.pop();

			if (0 == brr[1])
				break;
			if (!fff)
				printf("\n");
			fff = false;

			for (int i = 2; i <= N; i++)
				scanf("%d", &brr[i]);

			int index = 1, cur = 1;
			while (index <= N && flag)
			{
				if (brr[index] == cur)
				{
					index++;
					cur++;
				}
				else if (!rails.empty() && rails.top() == brr[index])
				{
					rails.pop();
					index++;
				}
				else if (cur <= N)
				{
					rails.push(cur);
					cur++;
				}
				else
					flag = false;
			}//while index 
			if (!flag)
				printf("No");
			else
				printf("Yes");
		}//while brr
	}//while N != 0
	return 0;
}