#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while(cin>>str)
	{
		int i = str.find_last_of('3',str.size());
		cout<<i<<endl;
	}
	return 0;
}