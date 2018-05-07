#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <set>

#include "hello.h"
extern int hello;


using namespace std;
const int maxn = 30;

bool cn[maxn];
char str[4000];
set<int> neightbors[maxn];
int res_k;
int ans[maxn];
int res_ans[maxn];
bool visited[maxn];
int kg = 0;


void read()
{
	char *sp = ";";
	char *p = strtok(str, sp);
	for (int i = 0; i < maxn; i++)
		neightbors[i].clear();

	memset(visited, false, sizeof(visited));
	memset(cn, false, sizeof(cn));
	while (p)
	{
		int nod = p[0] - 'A';
		cn[nod] = true;
		for (int i = 2; i < strlen(p); i++)
		{
			cn[p[i] - 'A'] = true;
			neightbors[nod].insert(p[i] - 'A');
			neightbors[p[i] - 'A'].insert(nod);
		}
		p = strtok(NULL, sp);
	}//while
}


void DFS(int layer, int tmp_bandwith)
{
	if (kg == layer)
	{
		if (tmp_bandwith < res_k)
		{
			res_k = tmp_bandwith;
			for (int i = 0; i < layer; i++)
				res_ans[i] = ans[i];
		}
	}

	for (int i = 0; i < maxn; i++)
	{
		if (!cn[i] || visited[i])
			continue;
		visited[i] = true;
		ans[layer] = i;

		bool flag = true;
		int tmp_k = 0;
		for (int j = 0; j < layer; j++)
		{
			if (neightbors[i].end() != neightbors[i].find(ans[j]))
			{
				int k = layer - j;
				if (k > res_k)
				{
					flag = false;
					break;
				}
				if (k > tmp_k)
					tmp_k = k;
			}
		}//for int j

		if (flag)
		{
			int tmp_b = max(tmp_k, tmp_bandwith);
			DFS(layer + 1, tmp_b);
		}
		visited[i] = false;
	}//for int i
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (true)
	{
		scanf("%s", str);
		res_k = 0x7fffffff;
		if ('#' == str[0])
			break;
		read();
		kg = 0;
		for (int i = 0; i < maxn; i++)
			if (cn[i])
				kg++;
		DFS(0, 0);
		for (int i = 0; i < maxn; i++)
		{
			if(cn[i])
				printf("%c ", 'A' + res_ans[i]);
		}
		printf("-> %d\n", res_k);
	}

	print();
	printf("%d\n", hello);
	system("pause");
	return 0;
}