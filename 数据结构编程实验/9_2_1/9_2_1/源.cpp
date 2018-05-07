#include <iostream>
using namespace std;

int main()
{
	freopen("sin","r",stdin);
	freopen("out.txt","w",stdout);
	int casenum;
	cin>>casenum;
	for(int count = 1;count < casenum + 1;count++)
	{
		int a,b;
		cin>>a>>b;
		int left = 0,right= 0;
		while(a > 1 || b > 1)
		{
			if(a > b)
			{
				int tmp = (a - 1)/b;
				left += tmp;
				a -= tmp * b;
			}
			else
			{
				int tmp = (b- 1)/a;
				right += tmp;
				b -= tmp * a;
			}
		}
		cout<<"Scenario #"<<count<<":"<<endl<<left<<" "<<right<<endl<<endl;
	}//for
	return 0;
}