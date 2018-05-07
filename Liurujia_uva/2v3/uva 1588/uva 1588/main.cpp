#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <algorithm>

using namespace std;

string bott, topt;

int work()
{
	int res_length = -1;
	for (int incent = 0; incent < bott.size(); incent++)
	{
		bool flag = true;
		for (int i = incent, j = 0; i < bott.size() && j < topt.size(); i++, j++)
		{
			if (bott[i] + topt[j] - 2 * '0' > 3)
			{
				flag = false;
				break;
			}
		}//for int i
		if (flag)
		{
			res_length = max(incent + topt.size(), bott.size());
			break;
		}
	}//for int incent
	if (res_length < 0)
		res_length = topt.size() + bott.size();
	return res_length;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> bott >> topt)
	{
		int r1 = work();
		swap(bott, topt);
		int r2 = work();
		int res_length = min(r1, r2);
		cout << res_length << endl;
	}//while cin
	return 0;
}