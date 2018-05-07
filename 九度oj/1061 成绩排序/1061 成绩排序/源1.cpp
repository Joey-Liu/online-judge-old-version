#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 100000 + 100;
int N, C;

struct student {
	string lnu;
	string name;
	int grades;
};

student stu[maxn];

int cmp1(const void * p1, const void * p2)
{
	student * a = (student *)p1;
	student * b = (student *)p2;

	int ag = atoi(a->lnu.data());
	int bg = atoi(b->lnu.data());

	return ag - bg;
}

int cmp2(const void * p1, const void * p2)
{
	student * a = (student *)p1;
	student * b = (student *)p2;
	
	if (a->name != b->name)
		return strcmp(a->name.data(), b->name.data());
	else
	{
		int ag = atoi(a->lnu.data());
		int bg = atoi(b->lnu.data());

		return ag - bg;
	}
}

int cmp3(const void * p1, const void * p2)
{
	student * a = (student *)p1;
	student * b = (student *)p2;

	if (a->grades != b->grades)
		return a->grades - b->grades;
	else
	{
		int ag = atoi(a->lnu.data());
		int bg = atoi(b->lnu.data());

		return ag - bg;
	}
}


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int kaseCount = 0;
	while (cin >> N >> C)
	{
		if (0 == N && 0 == C)
			break;
		for (int i = 0; i < N; i++)
			cin >> stu[i].lnu >> stu[i].name >> stu[i].grades;

		switch (C)
		{
		case 1:
			qsort(stu, N, sizeof(student), cmp1);
			break;
		case 2:
			qsort(stu, N, sizeof(student), cmp2);
			break;
		case 3:
			qsort(stu, N, sizeof(student), cmp3);
			break;
		default:
			break;
		}

		cout << "Case " << ++kaseCount << ":" << endl;
		for (int i = 0; i < N; i++)
			cout << stu[i].lnu << " " << stu[i].name << " " << stu[i].grades << endl;


	}

	return 0;
}