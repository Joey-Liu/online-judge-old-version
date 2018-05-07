#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

const int maxn = 1000 + 100;
struct stu {
	string name;
	int age;
	double grades;
};

stu students[maxn];
int N;

int cmp(const void * p1, const void * p2)
{
	stu * a = (stu *)p1;
	stu * b = (stu *)p2;

	if (a->grades != b->grades)
		return a->grades - b->grades;
	else
	{
		return strcmp(a->name.data(), b->name.data());
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> students[i].name >> students[i].age >> students[i].grades;
	
	qsort(students, N, sizeof(stu), cmp);
	for (int i = 0; i < N; i++)
		cout << students[i].name << " " << students[i].age << " " << students[i].grades << endl;
	return 0;
}