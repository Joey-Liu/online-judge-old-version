#include <iostream>
#include <string>
#include <sstream>
#include <list>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

struct Tnode	//Ҷ�ӽڵ�
{
	string name;
	Tnode *f;//�洢���ڵ�,��ʼ��ʱ ��Ҫ����
	list<Tnode* > son;//�洢���ӽڵ�
};

map<string ,Tnode*> bash;//hash ����ֱ�Ӳ�ѯָ��
Tnode* root;

void print(int dep,Tnode* tp)//depΪ ��㵱ǰ����
{
	for(int i = 0;i < dep;i++)
		cout<<"+";
	cout<<tp->name<<endl;

	for(list<Tnode* >::iterator it = tp->son.begin(); it != tp->son.end();it++)//����������
		print(dep + 1,*it);
}

void hires(string s1,string s2)
{
	Tnode* fa = bash[s1];
	Tnode* s = new Tnode;
	
	s->name = s2;
	s->f = fa;

	fa->son.push_back(s);
	bash[s2] = s;//����hash���м�¼
}

void fire(string s)
{
	Tnode* tp = bash[s];
	Tnode* fa = tp->f;
	bash.erase(s);//����ɾ�� s �ļ�¼ �������� �ı� ���ӽڵ� ��¼

	while(tp->son.size() != 0)
	{
		tp->name = tp->son.front()->name;//���ӽڵ����
		bash[tp->name] = tp;//���ӽڵ� ��bash�� ָ��ı�
		tp = tp->son.front();
	}
	
	tp->f->son.remove(tp);//ɾ�����û�������Ľ��
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
		//�ѵ�һ���ո������ȡ��
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
	//�Ӹ��ڵ㰤�� free ��
	post(root);
}//while case
	return 0;
}