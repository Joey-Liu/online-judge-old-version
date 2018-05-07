#include <iostream>
#include <map>
#include <string>
#include <sstream> 
#include <memory.h>
using namespace std;
map<char,int> record;
const int maxn = 2000 + 10;
bool u[maxn];

void prime()
{
	memset(u,true,sizeof(u));
	u[0] = u[1] = false;
	for(int i = 2;i < maxn;i++)
	{
		if(u[i])
		{
			for(int j = 2; i * j < maxn;j++)
				u[i * j] = false;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	prime();
	string str;
	int casenum;
	char ch;
	cin>>casenum;
	cin.get();
	for(int cnt = 1;cnt <= casenum;cnt++)
	{
		record.clear();
		getline(cin,str);
		istringstream ss(str);
		while(ss>>ch)
			record[ch]++;
		cout<<"Case "<<cnt<<": ";
		
		bool flag = true;
		for(map<char,int>::iterator it = record.begin();it != record.end();it++)
		{
			if(u[(*it).second])
			{
				flag = false;
				cout<<(*it).first;
			}
		}
		if(flag)
			cout<<"empty";
		cout<<endl;
	}
	return 0;
}