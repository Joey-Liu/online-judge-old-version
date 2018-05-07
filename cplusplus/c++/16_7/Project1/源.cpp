#include <iostream>
#include <vector>
#include <string>

const int NUM = 5;
using namespace std;
int main()
{
	vector<int> Rating(NUM);
	vector<string> titles(NUM);
	cout<<"You will do exactly as told,you will enter "
		<<NUM<<" book titles and your ratings(0-10).\n";
	int i;
	for(i=0;i<NUM;i++)
	{
		cout<<"Enter title #"<<i+1<<":";
		getline(cin,titles[i]);
		cout<<"Enter your rating(0-10):";
		cin>>titles[i];
		cin.get();
	}
	cout<<"Thank you.You entered the following:\n"
		<<"Rating\tBooks\n";
	for(i=0;i<NUM;i++)
		cout<<titles[i]<<"\t"<<Rating[i]<<endl;
	system("pause");
	return 0;
}

