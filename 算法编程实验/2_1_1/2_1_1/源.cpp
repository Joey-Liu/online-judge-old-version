#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

void translate(string str)
{
	for(int i = 0;i < str.size();i++)
	{
		str.size();
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			/*
			int index = str[i] - 'A' + 1 - 5;
			if(index <= 0)
				index += 26;
			cout << char('A' + index - 1);
			*/
			int index = str[i] - 'A' + 1;
			index = (index + 21) % 26;
			if (index == 0)
				index = 26;
			cout << char('A' + index - 1);
		}
		else
			cout<<str[i];
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string ss;
	while(cin>>ss)
	{
		if("START"==ss)
		{
			getchar();
			getline(cin,ss,'\n');
			translate(ss);
			cout<<endl;
		}
		else if("END"==ss)
			continue;
		else if("ENDOFINPUT")
			break;
	}
	return 0;
}