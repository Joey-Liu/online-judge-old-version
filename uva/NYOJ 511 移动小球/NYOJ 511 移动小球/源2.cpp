#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<cstdio>  
#include<algorithm>  
using namespace std;
int l[10010], r[10010];

int main()
{
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int num, query;
		char ope;
		int x, y;
		scanf("%d %d", &num, &query);
		for (int i = 1; i <= num; ++i) //Ô¤´¦Àí  
		{
			l[i] = i - 1;
			r[i] = i + 1;
		}
		r[num] = 1;
		l[1] = num;
		for (int i = 0; i < query; ++i)
		{
			getchar();
			scanf("%c %d %d", &ope, &x, &y);
			if (ope == 'A')
			{
				r[l[x]] = r[x]; l[r[x]] = l[x];
				r[x] = y;
				l[x] = l[y];
				l[r[x]] = x;
				r[l[x]] = x;
			}
			else if (ope == 'B')
			{
				r[l[x]] = r[x]; l[r[x]] = l[x];
				l[x] = y;
				r[x] = r[y];
				l[r[x]] = x;
				r[l[x]] = x;
			}
			else
				printf("%d\n", x ? r[y] : l[y]);
		}
	}
	return 0;
}