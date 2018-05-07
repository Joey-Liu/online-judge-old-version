#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string>
#include <memory>
#include <map>
#include <queue>

using namespace std;
const int maxn = 10 + 10;
int h, w, a, b;
string img[maxn];
string img_cp[maxn * maxn];

void copy_img()
{
	for (int ai = 0; ai < a; ai++)
	{
		string tmp = "";
		for (int row = 0; row < h; row++)
		{
			for (int bi = 0; bi < b; bi++)
				tmp += img[row];
			cout << tmp;
			cout << endl;
			tmp = "";
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> h >> w >> a >> b;
	for (int i = 0; i < h; i++)
		cin >> img[i];
	copy_img();
	return 0;
}