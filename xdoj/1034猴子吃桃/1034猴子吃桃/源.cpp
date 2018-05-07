#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <algorithm>

using namespace std;
int casenum;
int sum, ans, taozi;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	cin >> casenum;
	while (casenum--)
	{
		cin >> sum;
		taozi = 1;
		ans = 0;
		while (true)
		{
			if (sum - taozi >= 0)
			{
				sum -= taozi;
				taozi *= 2;
				ans++;
			}
			else
				break;
		}//while true
		taozi /= 2;			//结束前一个猴子的桃子
		if (sum > taozi)
			cout << ans + 1 <<" "<<sum << endl;
		else
			cout << ans <<" "<< taozi << endl;
	}
	return 0;
}