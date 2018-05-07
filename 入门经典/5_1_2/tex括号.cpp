#include <iostream>
using namespace std;

int main()
{
	bool flag=false;
	char ch;
	cin.get(ch);
	while(cin.fail()==false)
	{
		if('"'==ch)
		{
			if(false==flag)
			    cout<<"``";
			else
				cout<<ch;
			flag=!flag;
			cin.get(ch);
			continue;o
		}
		cout<<ch;
		cin.get(ch);
	}
	system("pause");
	return 0;
}

