#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;
const int maxn = 10000 + 100;
int database[maxn][10 + 5];
vector<string> str_vec;
map<string, int> dict;
map<pair<int, int>, int> pair_dict;
int n, m;
string data_line;
bool flag = false;
int res_r1, res_r2, res_c1, res_c2;

int find_id(string str)
{
	if (0 != dict.count(str))
		return dict[str];
	str_vec.push_back(str);
	dict[str] = str_vec.size() - 1;
	return str_vec.size() - 1;
}

void work()
{
	flag = false;
	for (int c1 = 0; c1 < m; c1++)
	{
		for (int c2 = c1 + 1; c2 < m; c2++)
		{
			pair_dict.clear();
			for (int r = 0; r < n; r++)
			{
				int p1 = database[r][c1], p2 = database[r][c2];
				pair<int, int> pa(p1, p2);
				if (0 == pair_dict.count(pa))
					pair_dict[pa] = r;
				else
				{
					res_r1 = pair_dict[pa];
					res_r2 = r;
					res_c1 = c1;
					res_c2 = c2;
					flag = true;
					break;
				}
			}//for int r
			if (flag)
				break;
		}//for int c2
		if (flag)
			break;
	}//for int c1
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (cin >> n >> m)
	{
		memset(database, 0, sizeof(database));
		str_vec.clear();
		dict.clear();
		pair_dict.clear();
		cin.get();
		for (int i = 0; i < n; i++)
		{
			getline(cin, data_line);
			int index = 0, cnt = 0;
			string str = "";
			while (index < data_line.length())
			{
				if (',' != data_line[index])
					str += data_line[index];
				else
				{
					database[i][cnt++] = find_id(str);
					str = "";
				}
				index += 1;
			}//while
			database[i][cnt] = find_id(str);
		}//for int i
		work();
		if (!flag)
			cout << "YES" << endl;
		else
		{
			cout << "NO" << endl;
			cout << res_r1 + 1 << " " << res_r2 + 1<< endl;
			cout << res_c1 + 1<< " " << res_c2  + 1<< endl;
		}
	}//while
	return 0;
}