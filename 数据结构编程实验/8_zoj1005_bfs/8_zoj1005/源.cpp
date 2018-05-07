#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100 + 10;
bool visited[maxn][maxn];//记录两个水壶的状态
struct Node
{
	int x,y,step;
	Node(int tx,int ty,int tstep)
	{
		x = tx;
		y = ty;
		step = tstep;
	}
};
queue< Node> que;//bfs队列

struct Path
{
	int mod;
	int parent;
	Path(int _mod,int _parent)
	{
		mod = _mod;//本状态由何种方式产生
		parent = _parent;//父母结点
	}
};
vector< Path> vec;//记录路径,最后一个即为所求状态

int a_pot,b_pot,target;

int bfs()
{
	memset(visited,false,sizeof(visited));
	visited[0][0] = true;

	vec.clear();
	while(!que.empty())
		que.pop();

	int order = -1;//各个结点在vec中下表
	Node parent(0,0,0);
	que.push(parent);
	vec.push_back(Path(0,-1));
	
	int tmpx,tmpy;
	while(!que.empty())
	{
		order++;
		parent = que.front();
		que.pop();

		////////6种情况依次入队
		//mod 1
		tmpx = a_pot;
		tmpy = parent.y;
		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(1,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}

		//mod 2
		tmpx = parent.x;
		tmpy = b_pot;
		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(2,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}

		//mod 3
		if(parent.x + parent.y <= b_pot && parent.x > 0)
		{
			tmpx = 0;
			tmpy = parent.x + parent.y;
		}
		else if(parent.x > 0)
		{
			tmpy = b_pot;
			tmpx = parent.x + parent.y - b_pot;
		}

		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(3,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}

		//mod 4
		if(parent.x + parent.y <= a_pot && parent.y > 0)
		{
			tmpx = parent.x + parent.y;
			tmpy = 0;
		}
		else if(parent.y > 0)
		{
			tmpx = a_pot;
			tmpy = parent.x + parent.y - a_pot;
		}
		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(4,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}

		//mod 5
		tmpx = 0;
		tmpy = parent.y;
		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(5,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}

		//mod 6
		tmpy = 0;
		tmpx = parent.x;
		if(!visited[tmpx][tmpy])
		{
			visited[tmpx][tmpy] = true;
			vec.push_back(Path(6,order));
			if(tmpx==target || tmpy==target)
				return parent.step + 1;
			que.push(Node(tmpx,tmpy,parent.step + 1));
		}
	}//while que.empty()
	return -1;
}

void output(Path p)
{
	if(0==p.parent)
	{
		switch(p.mod)
		{
		case 1: printf("fill A\n");break;
		case 2: printf("fill B\n");break;
		case 3: printf("pour A B\n");break;
		case 4: printf("pour B A\n");break;
		case 5: printf("drop A\n");break;
		case 6: printf("drop B\n");break;
		}
	}//if
	else
	{
		output(vec[p.parent]);
		switch(p.mod)
		{
		case 1: printf("fill A\n");break;
		case 2: printf("fill B\n");break;
		case 3: printf("pour A B\n");break;
		case 4: printf("pour B A\n");break;
		case 5: printf("drop A\n");break;
		case 6: printf("drop B\n");break;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int ret;
	while(scanf("%d%d%d",&a_pot,&b_pot,&target) != EOF)
	{
		ret = bfs();
		if(-1 != ret)
		{
			printf("%d\n",ret);
			output(vec[vec.size() - 1]);
			printf("success\n");
		}
		else
			printf("impossible\n");
	}
	return 0;
}
