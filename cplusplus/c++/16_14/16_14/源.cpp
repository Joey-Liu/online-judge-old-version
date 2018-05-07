#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef int KeyType;
typedef pair<const KeyType,string> Pair;
typedef multimap<KeyType,string> MapCode;

int main()
{
	MapCode codes;
	
	codes.insert(Pair(415,"San Francisco"));
	codes.insert(Pair(510,"Oakland"));
	codes.insert(Pair(718,"Blooklyn"));
	codes.insert(Pair(415,"San Rafael"));
	codes.insert(Pair(510,"Berklely"));
	codes.insert(Pair(718,"Staten Island"));

	cout<<"Number of cities of area code 415: "
		<<codes.count(415)<<endl;
	cout<<"Number of cities of area code 718: "
		<<codes.count(718)<<endl;
	cout<<"NUmber of cities of area code 510: "
		<<codes.count(510)<<endl;

	cout<<"    Area      City"<<endl;
	MapCode::iterator ir;
	for(ir = codes.begin();ir!=codes.end();ir++)
		cout<<"    "<<ir->first<<"    "<<ir->second<<endl;
	
	pair<MapCode::iterator,MapCode::iterator> range
		=codes.equal_range(718);
	cout<<"Cites with area code 718:\n";
	for(ir=range.first;ir != range.second; ir++)
		cout<<(*ir).second<<endl;

	system("pause");
	return 0;
}