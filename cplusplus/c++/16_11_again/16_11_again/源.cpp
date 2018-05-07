#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;
void output(const string & s) { cout<<s<<endl<<" "; } 
int main()
{
	string s1[4]= {"fine","fish","fashion","fat"};
	string s2[2]= {"busy","bats"};
	string s3[2]= {"silly","singer"};
	vector<string> word(4);
	
	cout<<endl;
	copy(s1,s1 + 4,word.begin());
	for_each(word.begin(),word.end(),output);

	cout<<endl;
	copy(s2,s2 + 2,back_insert_iterator<vector<string> > (word));
	for_each(word.begin(),word.end(),output);

	cout<<endl;
	copy(s3,s3 + 2,insert_iterator<vector<string> > (word,word.begin() ));
	for_each(word.begin(),word.end(),output);
	cout<<endl;
	system("pause");
	return 0;
}
