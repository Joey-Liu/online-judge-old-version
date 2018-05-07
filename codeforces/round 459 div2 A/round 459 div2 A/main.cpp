#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <memory.h>

using namespace std;
const int maxn = 1000 + 100;
int n;
bool isFinbo[maxn];

void init()
{
	memset(isFinbo, false, sizeof(isFinbo));
	int a = 0, b = 1, c;
	while (true)
	{
		c = a + b;
		if (c > maxn)
			break;
		isFinbo[c] = true;
		a = b;
		b = c;
	}//while true
}

int main()
{
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (isFinbo[i])
			printf("%c", 'O');
		else
			printf("%c", 'o');
	}
	return 0;
}