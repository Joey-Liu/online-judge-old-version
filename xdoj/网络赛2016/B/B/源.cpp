#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>

using namespace std;
const int maxn = 90;
long long int fibs[maxn];

void init()
{
	fibs[0] = 0; fibs[1] = 1;
	for (int i = 2; i < maxn; i++)
		fibs[i] = fibs[i - 1] + fibs[i - 2];

}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	init();
	long long int num = 0;
	long long int res, index;
	while (cin >> num)
	{
		for (int i = 1; i < maxn; i++)
		{
			if (num > fibs[i])
			{
				num = num - fibs[i];
				res = fibs[i];
			}
			else
			{
				if (num > fibs[i - 1])
				{
					res = num;
					index = i;
				}
				else if (num < fibs[i - 1])
				{
					res = fibs[i - 1];
					index = i - 1;
				}
				else
				{
					index = i - 1;
					while (index - 1 >= 1 && fibs[index - 1] == fibs[index])
						index--;
				}
				break;
			}//else 
		}//for 
		cout << index << " " << res << endl;
	}//while cin>>num

	return 0;
}