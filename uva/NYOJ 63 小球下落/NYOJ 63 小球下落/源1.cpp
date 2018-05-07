#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int D, I;
	while (scanf("%d%d", &D, &I))
	{
		if (!D && !I)
			break;
		
		int res = 1;
		for (int k = 0; k < D - 1; k++)
		{
			if (I % 2)//left
			{
				I = (I + 1)>>1;
				res = (res << 1);
			}
			else
			{
				I = I >> 1;
				res = (res << 1) + 1;
			}
		}
		printf("%d\n", res);
	}//while
	return 0;
}