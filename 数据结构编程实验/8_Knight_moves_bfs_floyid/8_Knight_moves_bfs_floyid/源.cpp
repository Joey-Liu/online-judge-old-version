#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#include <memory.h>
using namespace std;

const int maxn = 9;
int step[maxn][maxn];
bool map[maxn][maxn];
string s1,s2;

struct position
{
	int row,col;
};
queue< position> que;
position start,dest;

bool in_range(position pos)
{
	if(pos.row > 0 && pos.row < 9 && pos.col > 0 && pos.col < 9)
		return true;
	return false;
}

position makepath(position pos,int i)
{
	position npos = pos;
	switch(i)
	{
	case 1:npos.row -= 2;npos.col += 1;break;
	case 2:npos.row -= 1;npos.col += 2;break;
	case 3:npos.row += 1;npos.col += 2;break;
	case 4:npos.row += 2;npos.col += 1;break;
	case 5:npos.row += 2;npos.col -= 1;break;
	case 6:npos.row += 1;npos.col -= 2;break;
	case 7:npos.row -= 1;npos.col -= 2;break;
	case 8:npos.row -= 2;npos.col -= 1;break;
	}
	return npos;
}

void bfs()
{
	memset(map,true,sizeof(map));
	memset(step,0,sizeof(step));

	while(!que.empty())
		que.pop();

	position parent,son;
	que.push(start);
	map[start.row][start.col] = false;

	while(!que.empty())
	{
		parent = que.front();
		que.pop();

		if(parent.row==dest.row && parent.col==dest.col)
			break;

		for(int i = 1;i <= 8;i++)
		{
			son = makepath(parent,i);
			if(in_range(son) && map[son.row][son.col])
			{
				map[son.row][son.col] = false;
				step[son.row][son.col] = step[parent.row][parent.col] + 1;
				que.push(son);
			}
		}
	}//while

	cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<step[dest.row][dest.col]<<" knight moves."<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(cin>>s1>>s2)
	{
		start.col = s1[0] - 'a' + 1;
		start.row = s1[1] - '0';
		dest.col = s2[0] - 'a' + 1;
		dest.row = s2[1] - '0';

		bfs();
	}
	return 0;
}