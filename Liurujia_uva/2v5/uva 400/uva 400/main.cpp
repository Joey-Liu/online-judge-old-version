#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

#define MAX(x, y) ((x) > (y) ? (x) : (y))

using namespace std;

const int maxn = 60;
vector<string> files;
int file_num = 0;
int max_length = -1;
string file_name;

void print_file_name(string f_name, int margin)
{
	cout << f_name;
	for (int i = 0; i < margin - f_name.size(); i++)
		cout << " ";
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	char dashes[61];
	for (int i = 0; i < 60; i++)
		dashes[i] = '-';
	dashes[60] = '\0';

	while (cin >> file_num)
	{
		files.clear();
		max_length = -1;
		for (int i = 0; i < file_num; i++)
		{
			cin >> file_name;
			files.push_back(file_name);
			max_length = MAX(max_length, (int)file_name.length());
		}//for int i
		sort(files.begin(), files.end());
				
		int cols = (maxn - max_length) / (max_length + 2) + 1;
		int rows = (int)ceil((double)file_num / cols);
		
		cout << dashes << endl;
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				int index = j*rows + i;
				if (index >= file_num)
					break;
				int margin = ((j == cols - 1) ? max_length : max_length + 2);
				print_file_name(files[index], margin);
			}
			cout << endl;
		}//for int i
	}//while cin
	return  0;
}

