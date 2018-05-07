#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <memory.h>

using namespace std;
const int maxn = 30 + 3;

bool dung[maxn][maxn][maxn];
int step[maxn][maxn][maxn];

struct position
{
	int L,R,C;
};
position start;
position dest;
queue<position> que;
bool hasfind;

int level,row,col;
void init()
{
	memset(dung,true,sizeof(dung));
	memset(step,0,sizeof(step));
	while(!que.empty())
		que.pop();
	hasfind = false;

	string str;
	for(int i = 0;i < level;i++)//i²ã
	{
		for(int j = 0;j < row;j++)
		{
			cin>>str;
			for(int k = 0;k < str.length();k++)
			{
				if('S'==str[k])
				{
					start.L = i;
					start.R = j;
					start.C = k;
				}
				else if('E'==str[k])
				{
					dest.L = i;
					dest.R = j;
					dest.C = k;
				}
				else if('#'==str[k])
					dung[i][j][k] = false;
			}//for k
		}//for row
	}//for level
}

bool in_range(position p)
{
	if(p.L >= 0 && p.L < level && p.R >= 0 && p.R < row && p.C >=0 && p.C <col)
		return true;
	return false;
}

bool judge_vis(position p)
{
	return dung[p.L][p.R][p.C];
}

position makepath(position p,int i)
{
	position pos = p;

	switch(i)
	{
	case 1:pos.C++;break;
	case 2:pos.R++;break;
	case 3:pos.C--;break;
	case 4:pos.R--;break;
	case 5:pos.L--;break;
	case 6:pos.L++;break;
	}
	return pos;
}

void bfs()
{
	position parent,npos;
	que.push(start);

	while(!que.empty())
	{
		parent = que.front();
		que.pop();
		if(parent.C==dest.C && parent.R==dest.R && parent.L==dest.L)
		{
			hasfind = true;
			break;
		}
		else
		{
			for(int i = 1;i <= 6;i++)
			{
				npos = makepath(parent,i);
				if(in_range(npos) && judge_vis(npos))
				{
					que.push(npos);
					dung[npos.L][npos.R][npos.C] = false;
					step[npos.L][npos.R][npos.C] = step[parent.L][parent.R][parent.C] + 1;
				}
			}
		}//else
	}//while

	if(hasfind)
		cout<<"Escaped in "<<step[dest.L][dest.R][dest.C]<<" minute(s)."<<endl;
	else
		cout<<"Trapped!"<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>level>>row>>col;
	while(level || row || col)
	{
		init();
		bfs();
		cin>>level>>row>>col;
	}
	return 0;
}