#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 1e+5 + 10;
int N, X, ans, gen[maxn * 2];


int work(int M)
{
	int tmp = M;
	while (M > 0)
	{
		tmp += M % 10;
		M /= 10;
	}
	return tmp;
}

void init()
{
	memset(gen, -1, sizeof(gen));
	for (int i = 0; i < maxn; i++)
	{
		int k = work(i);
		if (gen[k] == -1)
			gen[k] = i;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &N);
	init();
	while (N--)
	{
		scanf("%d", &X);
		
		if (gen[X] != -1)
			printf("%d\n", gen[X]);
		else
			printf("0\n");
	}//while
	return 0;
}