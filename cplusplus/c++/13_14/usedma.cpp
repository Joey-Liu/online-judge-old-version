#include <iostream>
#include "dma.h"
using namespace std;

int main()
{
	baseDMA shirt("Portabelly",8);
	lackDMA balloon("red","Blimpo",4);
	hasDMA map("Mercator","Buffalo Keys",5);
	
	cout<<"Displaying baseDMA object:"<<endl;
	cout<<shirt<<endl;

	cout<<"Displaying lackDMA object:"<<endl;
	cout<<balloon<<endl;

	cout<<"Displaying hasDMA object:"<<endl;
	cout<<map<<endl;
	
	lackDMA balloon2(balloon);
	cout<<"Result of lackDMA copy:\n";
	cout<<balloon2<<endl;

	hasDMA map2;
	map2=map;

	cout<<"Result of hasDMA copy:\n";
	cout<<map2<<endl;

	system("pause");
	return 0;
}
