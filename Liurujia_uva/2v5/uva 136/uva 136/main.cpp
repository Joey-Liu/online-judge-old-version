#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;
typedef long long LL;

int main()
{
	LL coff[] = { 2, 3, 5 };
	priority_queue<LL, vector<LL>, greater<LL> > pq;
	set<LL> ug;

	pq.push(1);
	ug.insert(1);
	for (int i = 0; i < 1499; i++)
	{
		LL x = pq.top(); pq.pop();
		for (int j = 0; j < 3; j++) 
		{
			LL candi = x * coff[j];
			if (!ug.count(candi))
			{
				ug.insert(candi);
				pq.push(candi);
			}
		}// for int j
	}//for int i
	LL res = pq.top();
	cout <<"The 1500'th ugly number is "<< res <<".\n";
	getchar();
	return 0;
}