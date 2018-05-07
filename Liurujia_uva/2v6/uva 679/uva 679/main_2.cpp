#include <iostream>
#include <stdio.h>

using namespace std;
const int maxn = (1 << 20) + 10;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int kasenum;
	scanf("%d", &kasenum);
	while (kasenum--)
	{
		int D, I, ind = 1, k = 0;
		scanf("%d%d", &D, &I);
		while (k < D - 1)
		{
			if (I % 2)
			{
				ind = ind * 2;
				I = (I + 1) / 2;
			}
			else 
			{
				ind = ind * 2 + 1;
				I = I / 2;
			}
			k += 1;
		}//while
		printf("%d\n", ind);
	}//while
	return 0;
}