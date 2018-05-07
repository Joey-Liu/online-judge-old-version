#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;

int main()
{
	string str;
	while(getline(cin,str))
	{
		long int record[5];
		memset(record,0,sizeof(record));
		for(long int i =0;i < str.size();i++)
		{
			switch (str[i])
			{
			case 'C':
				record[0]++;
				break;
			case 'T':
				record[1]++;
				break;
			case 'J':
				record[2]++;
				break;
			case 'H':
				record[3]++;
				break;
			case 'S':
				record[4]++;
				break;
			}
		}
		sort(record,record + 5);
		cout<<record[3] + record[4]<<endl;
	}
	return 0;
}
