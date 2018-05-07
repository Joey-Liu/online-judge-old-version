#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

using namespace std;
const int maxn = 4e5;
int mol, den, rep_pos, rep_length;
int Dec[maxn], visited[maxn];



void work()
{
	mol %= den;
	int dec_length = 0;
	int rem_temp = mol; //ำเสý
	int dec_temp = 0;   //ษฬ
	memset(visited, -1, sizeof(visited));
	memset(Dec, 0, sizeof(Dec));
	while (true)
	{
		mol = 10 * rem_temp;
		dec_temp = mol / den;
		//rem_temp = mol % den;
		
		Dec[dec_length] = dec_temp;
		if (visited[rem_temp] != -1)
		{
			rep_pos = visited[rem_temp];
			rep_length = dec_length - rep_pos;
			break;
		}
		else if (0 == rem_temp)
		{
			rep_length = 1;
			rep_pos = dec_length;
			break;
		}
		else
		{
			visited[rem_temp] = dec_length++;
		}
		rem_temp = mol % den;
	}//while
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (2 == scanf("%d%d", &mol, &den))
	{
		printf("%d/%d = %d.", mol, den, mol / den);
		work();
		//if (rep_pos)
		    for (int i = 0; i < rep_pos; i++)
			    printf("%d", Dec[i]);
		printf("(");
		/*if (!rep_pos)
		{
			rep_pos--;
		}*/
		int rep_end = rep_pos + rep_length;
		
		for (int i = rep_pos; i < MIN(50, rep_end); i++)
			printf("%d", Dec[i]);
		if (rep_end <= 50)
			printf(")");
		else
			printf("...)");
		printf("\n   %d = number of digits in repeating cycle\n\n", rep_length);
	}//while
	return 0;
}