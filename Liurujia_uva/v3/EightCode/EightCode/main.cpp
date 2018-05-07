#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef int State[9];

const int drow[] = { -1, 1, 0, 0 };
const int dcol[] = { 0, 0, -1, 1 };
const int maxn = 1e+6;

State st[maxn], goal;
int dist[maxn];


void init_lookup_table();
bool try_to_insert(int rear);


int bfs()
{
	init_lookup_table();
	int front = 1, rear = 2;
	while (front < rear)
	{
		State &s = st[front];
		if (!memcmp(goal, s, sizeof(State)))
			return front;
		
		int zero = 0;
		for (zero = 0; zero < 9; zero++)
			if (!s[zero])
				break;

		int row = zero / 3, col = zero % 3;
		for (int dir = 0; dir < 4; dir++)
		{
			int n_row = row + drow[dir];
			int n_col = col + dcol[dir];

			if (n_row >= 0 && n_row < 3 && n_col >= 0 && n_col < 3)
			{
				int n_zero = n_row * 3 + n_col;
				State & tts = st[rear];
				memcpy(tts, s, sizeof(State));

				tts[n_zero] = s[zero];
				tts[zero] = s[n_zero];
				dist[rear] = dist[front] + 1;
				if (try_to_insert(rear))
					rear++;

			}
		}//for int dir
		front++;
	}//while
	return 0;
}


const int hashsize = (1e+6) + 3;
int head[hashsize], nexts[hashsize];

void init_lookup_table()
{
	memset(head, 0, sizeof(head));
}

int hashs(State s)
{
	int nu = 0;
	for (int i = 0; i < 9; i++)
	{
		nu = nu * 10 + s[i];
	}
	return nu % hashsize;
}

int try_to_insert(int s)
{
	int hashvalue = hashs(st[s]);
	int u = head[hashvalue];
	while (u)
	{
		if (!memcmp(st[u], st[s], sizeof(State)))
			return 0;
		u = nexts[u];
	}

	nexts[s] = head[hashvalue];
	head[hashvalue] = s;
	return 1;
}