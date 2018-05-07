#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string word,temp;
	string fun("!@#$%^&*()-=_+~{},/.;'"":<>? ");
	while(getline(cin,word))
	{
		string::iterator pr = word.begin();
		string::size_type loc;
		while(string::npos != word.find_first_of(fun))
		{
			loc = word.find_first_of(fun);
			word.erase(pr + loc);
		}
		for(int i=0;i < word.size();i++)
			word[i] = tolower(word[i]);
		
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
