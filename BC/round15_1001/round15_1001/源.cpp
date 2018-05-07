#include <iostream>
#include <string>
#include<cstring>
#include<algorithm>
using namespace std;


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string male,female;
	while(cin>>male>>female)
	{
		int i;
		for(i = 0;i < male.length();i++)
		{
			if(male[i] != '_')
				continue;
			else
				break;
		}
		i++;
		for(;i < male.length();i++)
			cout<<male[i];
		cout<<"_small_";

		for(i = 0;i < female.length();i++)
		{
			if(female[i] != '_')
				continue;
			else
				break;
		}
		i++;
		for(;i < female.length();i++)
			cout<<female[i];
		cout<<endl;
	}
	return 0;
}