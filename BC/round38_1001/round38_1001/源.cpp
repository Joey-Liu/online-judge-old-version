#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;
struct node
{
	int x, y, z;
}stone[4],vect[4];


int cmp(const void * a, const void * b)
{
	node * _a = (node *)a;
	node * _b = (node *)b;

	if (_a->x != _b->x)
		return _a->x - _b->x;
	else if (_a->y != _b->y)
		return _a->y - _b->y;
	else
		return _a->z - _b->z;
}

//方楚持
int work(node n1, node n2)
{
	return n1.x * n2.x + n1.y * n2.y + n1.z * n2.z;
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int casenum;
	cin >> casenum;

	for (int cnt = 1; cnt <= casenum; cnt++)
	{
		for (int i = 0; i < 4; i++)
			cin >> stone[i].x >> stone[i].y >> stone[i].z;

		qsort(stone, 4, sizeof(node), cmp);
		
		vect[0].x = stone[0].x - stone[1].x;
		vect[0].y = stone[0].y - stone[1].y;
		vect[0].z = stone[0].z- stone[1].z;

		vect[1].x = stone[0].x - stone[2].x;
		vect[1].y = stone[0].y - stone[2].y;
		vect[1].z = stone[0].z - stone[2].z;

		int s1 = work(vect[0], vect[1]);//中持
		s1 = abs(s1);

		vect[2].x = stone[0].x - stone[3].x;
		vect[2].y = stone[0].y - stone[3].y;
		vect[2].z = stone[0].z - stone[3].z;

		vect[3].x = stone[2].x - stone[1].x;
		vect[3].y = stone[2].y - stone[1].y;
		vect[3].z = stone[2].z - stone[1].z;

		int s2 = work(vect[2], vect[3]) / 2;
		s2 = abs(s2);

		cout << "Case #" << cnt << ": ";
		if (s1 == s2)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}