/*
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 100000 + 10;

struct node
{
	int stunum;
	string name;
	int grade;
}stu[maxn];

int cmp1(const void * a,const void * b)//学号
{
	node* _a = (node *)a;
	node* _b = (node *)b;
	return (_a->stunum - _b->stunum);
}

int cmp2(const void * a,const void * b)//姓名
{
	node* _a = (node *)a;
	node* _b = (node *)b;
	if(_a->name != _b->name)
		return strcmp(_a->name.data(),_b->name.data());
	return (_a->stunum - _b->stunum);
}

int cmp3(const void * a,const void * b)//成绩
{
	node* _a = (node* )a;
	node* _b = (node* )b;
	if(_a->grade != _b->grade)
		return _a->grade - _b->grade;
	return (_a->stunum - _b->stunum);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 0;
	int num,kind;
	while(cin>>num && num != 0)
	{
		casenum++;
		cin>>kind;
		for(int i = 0;i < num;i++)
			cin>>stu[i].stunum>>stu[i].name>>stu[i].grade;
		if(1==kind)
			qsort(stu,num,sizeof(stu[0]),cmp1);
		else if(2==kind)
			qsort(stu,num,sizeof(stu[0]),cmp2);
		else
			qsort(stu,num,sizeof(stu[0]),cmp3);
		cout<<"Case "<<casenum<<":"<<endl;
		
		for(int i = 0;i < num;i++)
		{
			cout.setf(ios::right);
			cout.fill('0');
			cout.width(6);
			cout<<stu[i].stunum<<" ";
			cout<<stu[i].name<<" "<<stu[i].grade<<endl;
		}
	}
	return 0;
}
*/





#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;
const int maxn = 100000 + 10;

struct node
{
	char stunum[10];
	char name[10];
	int grade;
}stu[maxn];

int cmp1(const void * a,const void * b)//学号
{
	node* _a = (node *)a;
	node* _b = (node *)b;
	return strcmp(_a->stunum,_b->stunum);
}

int cmp2(const void * a,const void * b)//姓名
{
	node* _a = (node *)a;
	node* _b = (node *)b;
	if(_a->name != _b->name)
		return strcmp(_a->name,_b->name);
	return strcmp(_a->stunum,_b->stunum);
}

int cmp3(const void * a,const void * b)//成绩
{
	node* _a = (node* )a;
	node* _b = (node* )b;
	if(_a->grade != _b->grade)
		return _a->grade - _b->grade;
	return strcmp(_a->stunum,_b->stunum);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum = 0;
	int num,kind;
	while(1==scanf("%d",&num) && num != 0)
	{
		casenum++;
		scanf("%d",&kind);
		for(int i = 0;i < num;i++)
		{
			scanf("%s %s %d",stu[i].stunum,stu[i].name,&stu[i].grade);
		}
		if(1==kind)
			qsort(stu,num,sizeof(stu[0]),cmp1);
		else if(2==kind)
			qsort(stu,num,sizeof(stu[0]),cmp2);
		else
			qsort(stu,num,sizeof(stu[0]),cmp3);
		printf("Case %d:\n",casenum);
		
		for(int i = 0;i < num;i++)
		{
			/*
			cout.setf(ios::right);
			cout.fill('0');
			cout.width(6);
			cout<<stu[i].stunum<<" ";
			cout<<stu[i].name<<" "<<stu[i].grade<<endl;
			*/
			printf("%s %s %d\n",stu[i].stunum,stu[i].name,stu[i].grade);
		}
	}
	return 0;
}

