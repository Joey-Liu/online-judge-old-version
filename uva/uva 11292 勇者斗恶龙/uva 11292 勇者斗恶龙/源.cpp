#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

const int maxn = 20000 + 100;
int dra[maxn];
int kni[maxn];
int n, m;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cost = 0, index = 0;;
	while (2 == scanf("%d%d", &n, &m))
	{
		if (0 == n && 0 == m)
			break;
		for (int i = 0; i < n; i++)
			scanf("%d", &dra[i]);
		for (int i = 0; i < m; i++)
			scanf("%d", &kni[i]);

		sort(dra, dra + n);
		sort(kni, kni + m);

		cost = 0; index = 0;
		for (int i = 0; i < m; i++)
		{
			if (index >= n)
				break;
			if (kni[i] >= dra[index])
			{
				cost += kni[i];
				index++;
			}
		}

		if (index >= n)
			printf("%d\n", cost);
		else
			printf("Loowater is doomed!\n");
	}
	return 0;
}