#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

map <string,long int> telenumber;

void convert(string & s)
{
	int loc = s.find('-');
	while(string::npos != loc)
	{
		s.erase(loc,1);
		loc = s.find('-');
	}
	for(int i =0;i < s.size();i++)
	{
		if(s[i] >= 'A' && s[i] <= 'O')
			s[i] = '0' + (s[i] - 'A')/3 + 2;
		else if('P'==s[i] || 'R'==s[i] || 'S'==s[i])
			s[i] = '7';
		else if('T' <= s[i] && s[i] <= 'Y')
			s[i] = (s[i] - 'T')/3 + 8 + '0';
	}
	s.insert(3,"-");					//位置3前面插入 -
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("output_in.txt","w",stdout);
	int case_num;
	cin>>case_num;
	while(case_num--)
{
	long int num;
	string temp;
	cin>>num;
	cin.get();
	int num_x = num;
	while(getline(cin,temp) && num_x)
	{
		convert(temp);
		telenumber[temp]++;					//值增加1
		num_x--;
	}
	
	bool flag = true;
	map <string,long int>::iterator it;
	for(it = telenumber.begin();it != telenumber.end();it++)
	{
		if( (*it).second > 1)
		{
			flag = false;
			printf("%s %ld\n",(*it).first.c_str(),(*it).second);//////////////////////////////
		}
	}
	if(true== flag)
		printf("No duplicates.\n");
	if(case_num)
		printf("\n");
}
	return 0;
}
