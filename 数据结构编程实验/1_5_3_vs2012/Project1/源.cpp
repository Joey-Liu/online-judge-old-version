#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	while('#'!=s[0])
	{
		int i=0,sum=0;
		for(i=0;i<s.size();i++)
			if(' '!=s[i])
				sum += (s[i] - 'A' + 1) * (i+1);
		cout<<sum<<endl;
		getline(cin,s);
	}
	system("pause");
	return 0;
}


