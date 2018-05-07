#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <memory.h>

using namespace std;
const int maxn = 50000 + 100;
int parent[maxn], fnode = -1;
int values[maxn];
bool isleaf[maxn];
int num, root, target, nodeCnt = 0;
char ch;
bool hasPath = false;

void SkipWhite()
{
	int c;
	do 
	{
		c = getc(stdin);
	} while (isspace(c));

	ungetc(c, stdin);
}

void build_sons(int root)
{
	bool le = false, re = false;
	SkipWhite();
	scanf("%c", &ch); // for '('
	SkipWhite();
	scanf("%c", &ch);
	if ('-' == ch || '+' == ch || isdigit(ch))
	{
		ungetc(ch, stdin);
		scanf("%d", &num);
		values[nodeCnt] = num;
		parent[nodeCnt] = root;
		build_sons(nodeCnt++);
	}
	else
		le = true;

	if (!le)
	{
		SkipWhite();
		scanf("%c", &ch); //for ')'
	}

	SkipWhite();
	scanf("%c", &ch); // for '('
	SkipWhite();
	scanf("%c", &ch);
	if ('-' == ch || '+' == ch || isdigit(ch))
	{
		ungetc(ch, stdin);
		scanf("%d", &num);
		values[nodeCnt] = num;
		parent[nodeCnt] = root;
		build_sons(nodeCnt++);
	}
	else
		re = true;
	if (!re)
	{
		SkipWhite();
		scanf("%c", &ch); //for ')'
	}

	if (re && le)
		isleaf[root] = true;
}

void findPath()
{
	for (int i = 0; i < nodeCnt; i++)
	{
		int summ = 0;
		if (!isleaf[i])
			continue;
		int index = i;
		do
		{
			summ += values[index];
			index = parent[index];
		} while (index != -1);
		
		if (summ == target)
		{
			hasPath = true;
			break;
		}
	}//for
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (1 == scanf("%d", &target))
	{
		nodeCnt = 0;
		memset(isleaf, false, sizeof(isleaf));
		memset(parent, -1, sizeof(parent));
		hasPath = false;

		while (true)
		{
			SkipWhite();
			scanf("%c", &ch); // for '('
			//scanf("%d", &num);
			//values[nodeCnt] = num;
			//build_sons(nodeCnt++);
			SkipWhite();
			scanf("%c", &ch);
			if ('-' == ch || '+' == ch || isdigit(ch))
			{
				ungetc(ch, stdin);
				scanf("%d", &num);
				values[nodeCnt] = num;
				parent[nodeCnt] = -1;
				build_sons(nodeCnt++);
				SkipWhite();
				scanf("%c", &ch);
			}
			break;
		}
		findPath();
		printf("%s\n", (hasPath ? "yes" : "no"));
	}//while scanf
	return 0;
}