#include <iostream>
#include <stdio.h>
#define NUM 10
#define SIZE 2000

using namespace std;

int get_next(int x)
{
	int a,b,len,n;
	char num[NUM];
	sprintf(num,"%d",x);
	n=len=strlen(num);
	
	for(int i=0;i<len;i++)
	{
		for(int j=i;j<len;j++)
			if(num[i]>num[j])
			{
				char ch=num[i];
				num[i]=num[j];
				num[j]=ch;
			}
	}
	//cout<<num<<endl;
	sscanf(num,"%d",&b);

	i=0;
	while(i < n/2)
	{
		char ch=num[i];
		num[i]=num[n-1-i];
		num[n-i-1]=ch;
		i++;
	}
	//cout<<num<<endl;
	sscanf(num,"%d",&a);

	return a-b;
}




int main()
{
	bool flag=false;
	int x,i,temp,count,num[SIZE];
	cin>>x;
	i=count=0;
	num[i]=x;
	i++;

	cout<<x;
	int j=0;
	while(true)
	{
		temp=get_next(x);
		while(j<i)
		{
			if(temp==num[j])
			{
				flag=true;
				break;
			}
			j++;
		}
		
		cout<<"->"<<temp;
		if(true==flag)
			break;
		num[i++]=temp;
		x=temp;
	}
	cout<<"ÖÜÆÚ£º"<<j+15;
	cout<<"\n";
	return 0;
}


