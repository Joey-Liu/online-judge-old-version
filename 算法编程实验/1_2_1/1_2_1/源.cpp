#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	while(casenum--)
	{
		int length,num;
		int pos,ear = 0,last = 0;
		cin>>length>>num;

		for(int i = 0;i < num;i++)
		{
			cin>>pos;
			if(pos > last)
				last = pos;
			if(length - pos > last)
				last = length - pos;

			pos = length - pos > pos ? pos : length - pos;
			if(pos > ear)
				ear = pos;
		}
		cout<<ear<<" "<<last<<endl;
	}
	return 0;
}