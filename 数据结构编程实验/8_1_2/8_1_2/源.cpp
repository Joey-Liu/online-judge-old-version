#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

struct Tnode	//叶子节点
{
	string name;
	Tnode *f;//存储父节点,初始化时 需要至零
	list<Tnode* > son;//存储儿子节点
};

map<string ,Tnode*> bash;//hash 便于直接查询指针
Tnode* root;

void print(int dep,Tnode* tp)//dep为 结点当前层数
{
	for(int i = 0;i < dep;i++)
		cout<<"+";
	cout<<tp->name<<endl;

	for(list<Tnode* >::iterator it = tp->son.begin(); it != tp->son.end();it++)//可能有问题
		print(dep + 1,*it);
}

void hires(string s1,string s2)
{
	Tnode* fa = bash[s1];
	Tnode* s = new Tnode;
	
	s->name = s2;
	s->f = fa;

	fa->son.push_back(s);
	bash[s2] = s;//增加hash表中记录
}

void fire(string s)
{
	Tnode* tp = bash[s];
	Tnode* fa = tp->f;
	bash.erase(s);//首先删除 s 的记录 这样才能 改变 儿子节点 记录

	while(tp->son.size() != 0)
	{
		tp->name = tp->son.front()->name;//儿子节点晋升
		bash[tp->name] = tp;//儿子节点 在bash中 指针改变
		tp = tp->son.front();
	}
	
	tp->f->son.remove(tp);//删除最后没有下属的结点
}

void post(Tnode* tp)
{
	for(list<Tnode* >::iterator it = tp->son.begin();it != tp->son.end();it++)
		post(*it);
	free(tp);
}

int main()
{
	freopen("zojin.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	cin.get();
	while(casenum--)
{
	bash.clear();
	cin.clear();

	string CEO;
	cin>>CEO;
	root = new Tnode;
	root->name = CEO;
	root->f = NULL;
	bash[CEO] = root;

	cin.get();
	string s1,s2;
	char name[150];
	cin.get(name,150);
	while(name[0] != '\0')
	{
		string str = name;
		if("print"==str)
		{
			print(0,root);
			for(int i = 0;i < 60;i++)
				printf("-");
			if(casenum)
				cout<<endl;
		}
		//把第一个空格的内容取出
		else
		{
			istringstream ss(str);
			ss>>s1;
			if("fire"==s1)
			{
				ss>>s2;
				fire(s2);
			}
			else//hires
			{
				ss>>s2;
				ss>>s2;
				hires(s1,s2);
			}
		}
		cin.get();
		cin.get(name,150);
	}
	if(casenum)
		cout<<endl;
	//从根节点挨个 free 下
	post(root);
}//while case
	return 0;
}