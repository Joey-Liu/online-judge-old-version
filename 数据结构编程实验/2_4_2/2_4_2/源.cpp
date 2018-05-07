#include <iostream>
using namespace std;

int main()
{
	int i,j;
	while(cin>>i>>j)
	{
		if(i > j)
		{
			int a = i;
			i = j;
			j = a;
		}

		int to_i = i;

		int count = 1,max = 0;
		for(;i <= j;i++)
		{
			int temp = i;
			while(1 != temp)
			{
				count++;
				if((temp % 2))	//odd
					temp = temp * 3 + 1;
				else
					temp = temp /2;
			}
			if(max < count)
				max = count;
			count = 1;
		}
		cout<<to_i<<" "<<j<<" "<<max<<endl;
	}
	system("pause");
	return 0;
}

