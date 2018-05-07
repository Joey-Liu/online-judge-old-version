#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string word,temp;
	while(getline(cin,word))
	{
		temp = word;
		reverse(word.begin(),word.end());

		if(word==temp)
			cout<<"Yes.\n";
		else
			cout<<"No.\n";
	}
	system("pause");
	return 0;
}

