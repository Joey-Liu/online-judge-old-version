#include <iostream>
#include <map>
#include <string>
#include <list>
#include <stdio.h>

using namespace std;

struct Tman
{
	string name;
	Tman *f;//¸¸Ö¸Õë
	list<Tman* > son;//¶ù×ÓÖ¸Õë
	Tman()
	{
		f = NULL;
	}
};

map<string,Tman*> hash_;
Tman* root;

void print(int dep,Tman* now)
{
	if(NULL== now) return;
	for(int i = 1;i <= dep;i++)
		printf("+");
	cout<<now->name<<endl;
	
	for(list<Tman *>::iterator it = now->son.begin();it != now->son.end();it++)
		print(dep + 1,*it);
}

void hire(string n1,string n2)
{
	Tman* f = hash_[n1];
	Tman* s = new Tman;
	s->name = n2;
	s->f = f;
	f->son.push_back(s);

	hash_[n2] = s;
}

void fire(string sn)
{
	Tman* s = hash_[sn];
	hash_.erase(sn);

	while(s->son.size() != 0)
	{
		s->name = s->son.front()->name;
		hash_[s->name] = s;
		s = s->son.front();
	}
	Tman* tf = s->f;
	tf->son.remove(s);
	delete s;
}

void solve()
{
	string s1,s2;
	int i;
	cin>>s1;
	root = new Tman();
	
	hash_[s1] = root;
	root->name = s1;

	while(cin>>s1)
	{
		if("print"==s1)
		{
			print(0,root);
			for(i = 1;i <= 60;i++)
				printf("-");
			printf("\n");
		}
		else if("fire"==s1)
		{
			cin>>s2;
			fire(s2);
		}
		else
		{
			cin>>s2;
			cin>>s2;
			hire(s1,s2);
		}
	}
}

int main()
{
	freopen("hirefire.in","r",stdin);
	freopen("out.txt","w",stdout);
	solve();
	return 0;
}