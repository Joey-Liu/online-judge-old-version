#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<string,string> Pair;

int main()
{
	freopen("word.in.txt","r",stdin);
	freopen("output.txt","w",stdout);
	map<string,string> wordset;
	string s,temp;
	cin>>s;
	while("XXXXXX" != s)
	{
		temp = s;
		sort(temp.begin(),temp.end());
		wordset.insert(Pair(s,temp));
		cin>>s;
	}
	
	int num = wordset.size();
	cin>>s;
	while("XXXXXX" != s)
	{
		map<string,string>::iterator it;
		bool find = false;
		sort(s.begin(),s.end());
		for(it = wordset.begin();it !=wordset.end();it++)
		{
			if(s==(*it).second)
			{
				find = true;
				cout<<(*it).first<<endl;
			}
		}
		if(!find)
			cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
		cin>>s;
	}
	
	system("pause");
	return 0;
}
