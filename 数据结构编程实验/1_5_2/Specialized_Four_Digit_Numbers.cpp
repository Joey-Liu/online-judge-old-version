#include<iostream>
using namespace std;
struct stack
{
	int size;
	int* base;
	int top;
};
int turn(int n,int m,stack & two);
int main()
{
	for(int i=2992;i<=9999;i++)
	{
		stack one;
		one.base=new int [13];
		one.top=0;
		one.size=0;
		int s1=turn(i,10,one);
		int s2=turn(i,12,one);
		int s3=turn(i,16,one);
		if(s1==s2&&s1==s3)
			cout<<i<<endl;
		delete []one.base;
	}
	/*int sum=0;
	stack Tony;
    Tony.base=new int [13];
    Tony.top=0;
	Tony.size=0;
	int n=3;
	sum=turn(n,2,Tony);
	cout<<sum<<endl;*/
	//getchar();
	return 0;
}



int turn(int n,int m,stack & two)
{
	while(n)
	{
		two.base[two.top]=n%m;
		n=n/m;
		two.top++;
	}
	int sum=0;
	while(two.top)
	{
		sum=two.base[two.top-1]+sum;
		two.top--;
	}
	return sum;
}


