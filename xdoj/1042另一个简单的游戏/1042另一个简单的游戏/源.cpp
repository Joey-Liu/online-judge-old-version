#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>

using namespace std;
const int maxn = 100 + 10;
int casenum;
int n;
double num, a, b, tmp;
priority_queue < double, vector<double >, greater<double> > q;

int main()
{
	scanf("%d", &casenum);
	while (casenum--)
	{
		while (!q.empty())
			q.pop();

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &num);
			q.push(num);
		}
		
		while (q.size() > 1)
		{
			a = q.top(); q.pop();
			b = q.top(); q.pop();
			tmp = (a + b) / 2;
			q.push(tmp);
		}

		printf("%.2lf\n", q.top() + (1e-9));
	}//while

	return 0;
}