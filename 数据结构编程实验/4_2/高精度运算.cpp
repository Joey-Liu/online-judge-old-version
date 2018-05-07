#include<iostream>
#include<string>
using namespace std;
#define SIZE 100

int a[SIZE]={0};
int b[SIZE]={0};
int ADD[SIZE]={0};
int REDUCE[SIZE]={0};
int MUTIPLY[SIZE]={0};

int n_a,n_b;
string s_a,s_b;




void Add(const int a[],const int b[])
{
	int i=0;

	for(i=0;i<(n_a > n_b ? n_a : n_b); i++)
	{	
		ADD[i]=a[i]+b[i]+ADD[i];
		if(ADD[i]>9)
		{
			ADD[i+1]=ADD[i+1]+ADD[i]/10;
			ADD[i]=ADD[i]%10;
		}
		//cout<<ADD[i+1]<<"jejeje"<<endl;
	}
	//bool flag=false;
	cout<<endl;
	
	cout<<"i="<<i<<endl;
	
	for(;i>=0;i--)
	{
		if(i >= (n_a > n_b ? n_a : n_b))
		{
			if(ADD[i]>0)
				cout<<ADD[i];
			else
				continue;
		}
		else
			cout<<ADD[i];
	}
	cout<<endl;
}


void Reduce(const int a[],const int b[])
{
	for(int i=0;i<(n_a > n_b ? n_a : n_b); i++)
	{
		if(a[i]>b[i])
			REDUCE[i]=a[i]-b[i]+REDUCE[i];
		else
		{
			REDUCE[i]=a[i]+10-b[i]+REDUCE[i];
			REDUCE[i+1]--;
		}
	}

	
	for(;i>=0;i--)
	{
		if(0==REDUCE[i])
			continue;
		else
			cout<<REDUCE[i];
	}
	cout<<endl;
}
void Mutiply(const int a[],const int b[])
{
	for(int i=0;i<; i++)










void Read(const string & s,int num[],int & n_)
{
	int n=s.length();
	n_=n;
	for(int i=0;i<n;i++)
		num[i]=s[n-i-1]-'0';
}


int main()
{

	cin>>s_a;
	Read(s_a,a,n_a);
	cin>>s_b;
	Read(s_b,b,n_b);

	Add(a,b);
	Reduce(a,b);

	cout<<endl;
	//Reduce(a,b);
	cout<<endl;
	return 0;
}

	

