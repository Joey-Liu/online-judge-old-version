#include <iostream>
using namespace std;

int main()
{
	int num;
	cin>>num;

	while(num>0)
	{
		int n=0,i=1;
		while(n<num)
		{
			n=n+i;
			i++;
		}
		i--;		//���ֳ����ڵ�i��б����
		int a=1+n-num;
		int b=i-(n-num);
		cout<<a<<"/"<<b<<endl;
		cin>>num;
	}
	
	system("pause");
	return 0;
}
