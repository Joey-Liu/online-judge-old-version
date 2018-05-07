#include<iostream>
#include <stdlib.h>

using namespace std;

/*const long int max=100000;
int prime[max];
int total=0;

bool isprime(long k)
{
	for(int i=0;i<total;i++)
		if(0==k%prime[i])
			return false;
	return true;
}*/
bool isprime(long k)
{
	if(1==k)  return false;
	for(int i=2;i<k/2;i++)
		if(0==k%i)
			return false;
	return true;
}

int main()
{
	int i=2;
	/*for(i=2;i<max;i++)
	{
		if(isprime(i))
			prime[total++]=i;
	}
	prime[total]=max+1;*/
	long int m;
	int a,d,n,cnt=0;
	cin>>a;
	cin>>d;
	cin>>n;
	while(a||d||n)
	{
		cnt=0;
		for(m=a;cnt<n;m=m+d)
		{
			if(isprime(m))
			{
				//cout<<"?\n";
				cnt++;
			}
			//cout<<"!\n";
		}
		cout<<m-d<<endl;
		cin>>a;
		cin>>d;
		cin>>n;
	}
	return 0;
}



