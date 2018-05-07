#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

const int maxn = 1000 + 50;

struct node
{
	string name;
	int age;
	double marks;
}stu[maxn];

int cmp(const void * a,const void * b)
{
	node * _a = (node *)a;
	node * _b = (node *)b;
	if(_a->marks != _b->marks)
		return _a->marks - _b->marks;
	else if(_a->name != _b->name)
		return strcmp(_a->name.data(),_b->name.data());
	else
		return _a->age - _b->age;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int num;
	while(cin>>num)
	{
		for(int i = 0;i < num;i++)
			cin>>stu[i].name>>stu[i].age>>stu[i].marks;

		qsort(stu,num,sizeof(stu[0]),cmp);
		for(int i = 0;i < num;i++)
			cout<<stu[i].name<<" "<<stu[i].age<<" "<<stu[i].marks<<endl;
	}
	return 0;
}