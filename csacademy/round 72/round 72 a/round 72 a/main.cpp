#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int num, tmp, rever_num = 0;
	scanf("%d", &num);
	tmp = num;
	while (tmp != 0)
	{
		int t = tmp % 10;
		tmp /= 10;
		rever_num = rever_num * 10 + t;
	}
	printf("%d\n", rever_num);
	if (rever_num > num)
		printf("1\n");
	else
		printf("0\n");
	system("pause");
	return 0;
}