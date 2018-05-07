#include <iostream>
using namespace std;
const int num = 20;

int main()
{
	int D,I;
	while(cin>>D>>I)
	{
		int k=1;
		for(int i=1;i<D;i++)			//Ö»Ä£ÄâµôÂäd²ã
		{
			if(I%2)
			{
				k = 2 * k;
				I = I / 2 +1;
			}
			else
			{
				k = 2 * k + 1;
				I = I /2;
			}
		}
		cout<<k<<endl;
	}
	system("pause");
	return 0;
}

