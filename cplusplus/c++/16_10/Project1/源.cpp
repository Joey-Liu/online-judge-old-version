#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
int main()
{
	string str;
	getline(cin,str);
	int temp;
	vector<int> data;

	istringstream ss(str);
	while(ss>>temp)
		data.push_back(temp);
	cout<<"Your numbers are here:\n";
	ostream_iterator <int,char> out_iter(cout," ");
	copy(data.begin(),data.end(),out_iter);
	cout<<endl;

	cout<<"Implicit use of reverse iterator:\n";
	copy(data.rbegin(),data.rend(),out_iter);
	cout<<endl;

	cout<<"Explicit use of reverse iterator:\n";
	vector<int>::reverse_iterator ri;
	for(ri = data.rbegin();ri != data.rend();ri++)
		cout<<*ri<<' ';
	cout<<endl;

	system("pause");
	return 0;
}