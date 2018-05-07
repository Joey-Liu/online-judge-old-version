#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

const int maxn = 25 + 10;
int place[maxn];
int stack[maxn][maxn];
int top[maxn];
int number;

char oper[maxn], prep[maxn];
int a, b;

void init_place(int n)
{
	int posi = place[n];
	while (stack[posi][top[posi]] != n)
	{
		int temp = stack[posi][top[posi]];
		stack[temp][++top[temp]] = temp;
		place[temp] = temp;

		top[posi]--;
	}
}


void block_move(int a, int b)
{
	int posi = place[a];
	int posi_b = place[b];
	int index = top[posi];

	while (index >= 0 && stack[posi][index] != a)
		index--;

	for (int i = index; i <= top[posi]; i++)
	{
		stack[posi_b][++top[posi_b]] = stack[posi][i];
		place[stack[posi][i]] = posi_b;
	}
	top[posi] = index - 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		place[i] = i;
		stack[i][0] = i;
		top[i] = 0;
	}

	while (scanf("%s", oper))
	{
		if ('q' == oper[0])
			break;
		scanf("%d%s%d", &a, prep, &b);
		
		if (place[a] == place[b])
			continue;
		if ('m' == oper[0])
			init_place(a);
		if ('n' == prep[1])
			init_place(b);

		block_move(a, b);
	}
	for (int i = 0; i < number; i++)
	{
		cout << i << ":";
		if (top[i] < 0)
		{
			cout << endl;
			continue;
		}

		for (int j = 0; j <= top[i]; j++)
			cout << " " << stack[i][j];
		cout << endl;
	}//for int i
	return 0;
}