#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <string>
#include <queue>
#include <vector>

using namespace std;

const char * dirs = "NESW";
const char * turns = "FRL";

const int maxn = 9 + 5;

int dir_id(char c)
{
	return strchr(dirs, c) - dirs;
}

int turn_id(char c)
{
	return strchr(turns, c) - turns;
}

const int dr[] = { -1, 0, 1, 0 };
const int dc[] = { 0, 1, 0 ,-1 };

struct Node
{
	int r, c, dir;
};

int get_next_dir(int dir, int turn)
{
	if (!turn)
		return dir;
	if (1 == turn)
		return (dir + 1) % 4;
	else
		return (dir + 3) % 4;
}

Node walk(const Node & node, int turn)
{
	Node n;
	int dir = get_next_dir(node.dir, turn);
	
	n.r = node.r + dr[dir];
	n.c = node.c + dc[dir];
	n.dir = dir;
	return n;
}

int step[maxn][maxn][4];
Node parent[maxn][maxn][4];
bool maze[maxn][maxn][4][3];

int st_r, st_c, st_dir, goal_r, goal_c;
bool flag = false;

bool in_maze(Node node)
{
	if (node.r <= 0 || node.c <= 0 || node.r > 9 || node.c > 9)
		return false;
	return true;
}

void print_path(Node node)
{
	vector<Node> path;
	while (-1 != step[node.r][node.c][node.dir])
	{
		path.push_back(node);
		node = parent[node.r][node.c][node.dir];
	}
	Node ori;
	ori.r = st_r;
	ori.c = st_c;
	ori.dir = st_dir;
	path.push_back(ori);

	int ind = 0;
	for (int i = path.size() - 1; i >= 0; i--)
	{
		ind++;
		if (1 == ind % 10)
			printf(" ");
		printf(" (%d,%d)", path[i].r, path[i].c);
		
		if (0 == ind % 10)
			printf("\n");
	}
	if(0 != path.size() % 10)
		printf("\n");
}


void BFS()
{
	flag = false;
	Node st;
	st.r = st_r + dr[st_dir];
	st.c = st_c + dc[st_dir];
	st.dir = st_dir;

	queue<Node> que;
	que.push(st);
	step[st.r][st.c][st.dir] = 1;
	while (!que.empty())
	{
		Node node = que.front();
		que.pop();
		if (node.r == goal_r && node.c == goal_c)
		{
			flag = true;
			print_path(node);
			break;
		}
		for (int i = 0; i < 3; i++)
		{
			Node ne = walk(node, i);
			if (in_maze(ne) && maze[node.r][node.c][node.dir][i] && -1 == step[ne.r][ne.c][ne.dir])
			{
				step[ne.r][ne.c][ne.dir] = step[node.r][node.c][node.dir] + 1;
				parent[ne.r][ne.c][ne.dir] = node;
				que.push(ne);
			}
		}
	}
	if (!flag)
		printf("  No Solution Possible\n");
}



int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	string maze_name;
	while (cin >> maze_name)
	{
		if ("END" == maze_name)
			break;
		memset(step, -1, sizeof(step));
		memset(parent, 0, sizeof(parent));
		memset(maze, false, sizeof(maze));

		char c_dir;
		cin >> st_r >> st_c >> c_dir >> goal_r >> goal_c;
		st_dir = dir_id(c_dir);

		int a, b;
		while (cin >> a && a)
		{
			cin >> b;
			string str;
			while (true)
			{
				cin >> str;
				if ("*" == str)
					break;
				int dir = dir_id(str[0]);
				for (int i = 1; i < str.size(); i++)
				{
					int turn = turn_id(str[i]);
					maze[a][b][dir][turn] = true;
				}
			}
		}
		cout << maze_name << endl;
		BFS();

	}//while cin>>maze_name
	return 0;
}