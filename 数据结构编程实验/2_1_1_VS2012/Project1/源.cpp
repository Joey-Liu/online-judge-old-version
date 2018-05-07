#include <iostream>
using namespace std;
int main()
{
	int i=0;
	int n = 0,t1=0,t2=0,v=0,sum=0;
	cin>>n;
	while(-1 != n)
	{
		cin>>v>>t1;
		sum = t1 * v;
		t2 = t1;
		for(i=1;i<n;i++)
		{
			cin>>v>>t1;
			sum += (t1 - t2)*v;
			t2 = t1;
		}
		cout<<sum<<" miles"<<endl;
		sum = 0;
		cin>>n;
	}
	system("pause");
	return 0;
}
