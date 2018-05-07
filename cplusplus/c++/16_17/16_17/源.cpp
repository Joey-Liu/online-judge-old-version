#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string letters;
	while(cin>>letters &&letters != "quit")
	{
		sort(letters.begin(),letters.end());
		cout<<letters<<endl;
		while(next_permutation(letters.begin(),letters.end()) )
			cout<<letters<<endl;
	}
	cout<<"done"<<endl;
	return 0;
}
