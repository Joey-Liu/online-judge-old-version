#include <iostream>
#include <queue>
#include <memory.h>
#include <cstdlib>
using namespace std;

const int maxn = 50 + 5;

int step[maxn][maxn][maxn];
bool castle[maxn][maxn][maxn];
int level,row,col,limit;

struct position
{
	int L,R,C;
};
queue< position> que;
position start,dest;
bool escape;

bool in_range(position pos)
{
	if(pos.L >= 0 && pos.L < level && pos.R >= 0 && pos.R < row && pos.C >= 0 && pos.C < col)
		return true;
	return false;
}

position makepath(position pos,int mod)
{
	position npos = pos;
	switch(mod)
	{
	case 1:npos.R--;break;
	case 2:npos.C++;break;
	case 3:npos.R++;break;
	case 4:npos.C--;break;
	case 5:npos.L--;break;
	case 6:npos.L++;break;
	}
	return npos;
}

void init()
{
	memset(step,0,sizeof(step));
	memset(castle,true,sizeof(castle));
	start.C = start.R  = start.L = 0;
	int tmp;
	scanf("%d%d%d%d",&level,&row,&col,&limit);
	dest.C = col - 1;
	dest.R = row - 1;
	dest.L = level - 1; 
	escape = false;

	while(!que.empty())
		que.pop();

	for(int i = 0;i < level;i++)
	{
		for(int j = 0;j < row;j++)
		{
			for(int k = 0;k < col;k++)
			{
				scanf("%d",&tmp);
				if(1==tmp)
					castle[i][j][k] = false;
			}
		}//for int j
	}//for int i
}

void bfs()
{
	position parent,son;
	que.push(start);
	castle[start.L][start.R][start.C] = false;
	bool flag = true;

	while(!que.empty() && flag)
	{
		parent = que.front();
		que.pop();
		
		if(parent.L==dest.L && parent.R==dest.R && parent.C==dest.C)
		{
			escape = true;
			break;
		}

		for(int i = 1;i <= 6;i++)
		{
			son = makepath(parent,i);
			if(step[parent.L][parent.R][parent.C] > limit)
			{
				flag = false;
				break;
			}

			if(in_range(son) && castle[son.L][son.R][son.C])
			{
				castle[son.L][son.R][son.C] = false;
				step[son.L][son.R][son.C] = step[parent.L][parent.R][parent.C] + 1;
				que.push(son);
			}
		}
	}//while

	if(escape && step[dest.L][dest.R][dest.C] <= limit)
		printf("%d\n",step[dest.L][dest.R][dest.C]);
	else
		printf("-1\n");
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		init();
		if(level + row + col - 3 > limit)
			printf("-1\n");
		else if(castle[level-1][row-1][col-1]==false) 
		{
			printf("-1\n");
			continue;
		}
		else
			bfs();
	}
	return 0;
}