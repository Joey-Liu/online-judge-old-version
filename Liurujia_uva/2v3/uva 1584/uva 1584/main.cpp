#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

using namespace std;

int kase;
const int maxn = 100 + 10;
char dna[maxn];

bool less_str(int p, int q)
{
	int len = strlen(dna);
	for (int i = 0; i < len; i++)
	{
		if (dna[(p + i) % len] != dna[(q + i) % len])
			return dna[(p + i) % len] < dna[(q + i) % len];
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%s", dna);
		int len = strlen(dna), ans = 0;
		for (int i = 1; i < len; i++)
		{
			if (less_str(i, ans))
				ans = i;
		}
		for (int i = 0; i < len; i++)
			putchar(dna[(i + ans) % len]);
		putchar('\n');
	}//while
	return 0;
}