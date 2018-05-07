#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string str;
	cout<<"Enter the string you like(quit to quit):"<<endl;
	while(cin>>str && str != "quit")
	{
		int count = 1;
		cout<<"Permutations of "<<str<<":\n";
		sort(str.begin(),str.end());
		cout<<str<<endl;
		while(next_permutation(str.begin(),str.end()) )
		{
			cout<<str<<endl;
			count++;
		}
		cout<<"Amount of different strings is "<<count<<endl;
		cout<<"Enter the next string you like(quit to quit):"<<endl;
	}
	cout<<"See you!\n";
	system("pause");
	return 0;
}
