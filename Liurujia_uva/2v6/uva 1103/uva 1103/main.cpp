#include <iostream>
#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200 + 20;
int img_visited[maxn][maxn];
int img[maxn][maxn];
int H, W;
char str[maxn];
int res_cnt = 0, color_cnt = 0;

const int dr[] = { -1, 0 ,1, 0 };
const int dc[] = { 0, 1, 0, -1 };

int* convert(char ch)
{
	int num = 0;
	if (isalpha(ch))
		num = 10 + ch - 'a';
	else
		num = ch - '0';

	int *p = new int[4];
	for (int i = 0; i < 4; i++)
		p[i] = 0;

	int ind = 3;
	while (num)
	{
		int t = num % 2;
		num /= 2;
		p[ind] = t;
		ind--;
	}
	return p;
}	

bool in_map(int r, int c)
{
	if (r < 0 || r >= H || c < 0 || c >= W)
		return false;
	return true;
}

void DFS(int r, int c, int sym)
{
	img_visited[r][c] = sym;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (!img_visited[nr][nc] && in_map(nr, nc) && img[nr][nc] == img[r][c])
			DFS(nr, nc, sym);
	}
}

map<int, set<int> > neighbor;

void check_neighbor(int r, int c)
{
	int yanse = img_visited[r][c];
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (in_map(nr, nc) && img_visited[nr][nc] != yanse)
		{
			neighbor[yanse].insert(img_visited[nr][nc]);
		}
	}
}

void print_img()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << img[i][j];
		}
		cout << endl;
	}
}

const char *hyieo = "WAKJSD";

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (2 == scanf("%d%d", &H, &W))
	{
		if (!H && !W)
			break;
		memset(img, 0, sizeof(img));
		memset(img_visited, 0, sizeof(img_visited));
		
		for (int i = 0; i < H; i++)
		{
			scanf("%s", str);
			int ind = 1;
			for (int j = 0; j < W; j++)
			{
				int *p = convert(str[j]);
				for (int k = 0; k < 4; k++)
				{
					img[i + 1][ind] = p[k];
					ind++;
				}
				delete p;
			}
		}
		H += 2;
		W = W * 4 + 2;
		res_cnt = 0;
		color_cnt = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (!img_visited[i][j])
				{
					DFS(i, j, ++color_cnt);
					if (img[i][j])
						res_cnt++;
				}
			}
		}
		int back_ground_color = img_visited[H - 1][0];
		neighbor.clear();

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (img[i][j])
				{
					check_neighbor(i, j);
				}
			}
		}

		vector<int> res;
		vector<char> res_char;
		for (map<int, set<int>>::iterator it = neighbor.begin(); it != neighbor.end(); it++)
		{
			res.push_back(it->second.size());
		}
		sort(res.begin(), res.end());
		cout << "Case " << ++kasenum << ": ";
		for (int i = 0; i < res.size(); i++)
			res_char.push_back(hyieo[res[i] - 1]);
		sort(res_char.begin(), res_char.end());
		for (int i = 0; i < res_char.size(); i++)
			cout << res_char[i];
		cout << endl;

		//print_img();
	}//while
	return 0;
}