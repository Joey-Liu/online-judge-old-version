#include<iostream>
#include<string.h>
using namespace std;
#define SIZE 265
int compute(const char* data);

int main()
{
	//string data;
	char data[SIZE];
	//data=new char[SIZE];
	//cin.getline(data,255);
	gets(data);
	while(data[0]!='#')
	{
		int result=compute(data);
		cout<<result<<endl;
		gets(data);		
	}
	return 0;
}


int compute(const char* data)
{
	int n=strlen(data);
	int sum=0;
	for(int i=0;i<n;i++)
	{	
		if(data[i]!=' ')
		  sum=sum+(i+1)*(data[i]-'A'+1);
	}
	return sum;
}
