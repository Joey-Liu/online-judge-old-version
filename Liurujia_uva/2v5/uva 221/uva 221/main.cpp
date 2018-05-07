#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

const int maxn = 100 + 10;
struct Building
{
	double x, y, w, d, h;
	int id;

	bool operator < (const Building & b) const
	{
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

Building building[maxn];
double x_axis[maxn * 2];
int building_num, diff_x_axis;

bool cover(const Building & b, double xa)
{
	if (b.x <= xa && b.x + b.w >= xa)
		return true;
	return false;
}

bool visible(const Building & b)
{
	bool flag_vis = true;
	for (int i = 0; i < diff_x_axis - 1; i++)
	{
		flag_vis = true;
		double xa = (x_axis[i] + x_axis[i + 1]) / 2.0;
		if (cover(b, xa))
		{
			for (int j = 0; j < building_num; j++)
			{
				if (b.id == building[j].id)
					continue;
				if (building[j].y < b.y && cover(building[j], xa) && building[j].h >= b.h)
				{
					flag_vis = false;
					break;
				}
			}//for int j
			if (flag_vis)
				return true;
		}//if
	}
	return false;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kasenum = 0;
	while (1 == scanf("%d", &building_num) && building_num)
	{
		if (kasenum)
			printf("\n");
		for (int i = 0; i < building_num; i++)
		{
			scanf("%lf%lf%lf%lf%lf", &building[i].x, &building[i].y, 
				&building[i].w, &building[i].d, &building[i].h);
			building[i].id = i + 1;
		}
		for (int i = 0; i < building_num; i++)
		{
			x_axis[i * 2] = building[i].x;
			x_axis[i * 2 + 1] = building[i].x + building[i].w;
		}

		sort(building, building + building_num);
		sort(x_axis, x_axis + building_num * 2);
		diff_x_axis = unique(x_axis, x_axis + building_num * 2) - x_axis;

		printf("For map #%d, the visible buildings are numbered as follows:\n", ++kasenum);
		printf("%d", building[0].id);

		for (int i = 1; i < building_num; i++)
		{
			if (visible(building[i]))
				printf(" %d", building[i].id);
		}
		printf("\n");
	}//while
	return 0;
}