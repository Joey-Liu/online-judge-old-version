#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<const int,string> Pair;

int main()
{
	multimap <int,string> codes;

	codes.insert(Pair(415,"San Fransico"));
	codes.insert(Pair(510,"OakLand"));
	codes.insert(Pair(718,"BrookLin"));
	codes.insert(Pair(718,"Staten,Island"));
	codes.insert(Pair(415,"San Rafael"));
	codes.insert(Pair(510,"Berkely"));

	cout<<"Number of cities with area code 415: "
		<<codes.count(415)<<endl;
	cout<<"Number of cities with area code 718: "
		<<codes.count(718)<<endl;
	cout<<"Number of cities with area code 510: "
		<<codes.count(510)<<endl;
	cout<<"Area Code	 City"<<endl;

	multimap<int,string>::iterator it;
	for(it = codes.begin();it != codes.end();it++)
		cout<<"	"<<(*it).first<<"	 "<<(*it).second<<endl;
	pair<multimap<int,string>::iterator,multimap<int,string>::iterator> range = codes.equal_range(718);
	cout<<"Cites with area code 718"<<endl;
	for(it = range.first;it != range.second;it++)
		cout<<(*it).second<<endl;

	system("pause");
	return 0;
}

