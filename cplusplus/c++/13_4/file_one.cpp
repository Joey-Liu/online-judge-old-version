#include<iostream>
#include<string>
using std::string;
using std::ostream;
#include"Port.h"


Port::Port(const char* br,const char *st,int b)
{
	int n=strlen(br);
	brand=new char[n+1];
	strcpy(brand,br);
	strcpy(style,st);
	bottles=b;
}


Port::Port(const Port & p)
{
	int n=strlen(p.brand);
	delete [] brand;
	brand=new char[n+1];
	strcpy(brand,p.brand);
	strcpy(style,p.style);
	bottles=p.bottles;
}


Port & Port::operator =(const Port & p)
{
	if(this==&p)
		return *this;
	delete [] brand;
	int n=strlen(p.brand);
	brand=new char [n+1];
	strcpy(brand,p.brand);
	strcpy(style,p.style);
	bottles=p.bottles;
}


Port & Port::operator +=(int b)
{
	bottles+=b; 
	return *this;
}


Port & Port::operator -=(int b)
{
	if(b>bottles)
	{
		cout<<"Can't reduce so much"<<endl;
		return *this;
	}
	bottles-=b;
	return *this;
}

void Port::Show() const
{
	cout<<"Brand: "<<brand<<endl 
		<<"Kind: "<<style<<endl
		<<"Bottles: "<<bottles<<endl;
}


/*ostream & operator<<(ostream os,const Port & p)
{
	os<<p.bottles;
	return os;
} 最好定义在类里面*/


VintagePort::VintagePort():Port()
{
	nickname=NULL;
	year=0;
}


VintagePort::VintagePort(const char* br,const char* st,int b,const char * nn,int y):
Port(br,st,b)
{
	int n=strlen(nn);
	nickname=new char[n+1];
	strcpy(nickname,nn);
	year=y;
}

VintagePort::VintagePort(const VintagePort & vp):Port(vp)
{
	int n=strlen(nickname);
	nickname=new char[n+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}


VintagePort & VintagePort::operator =(const VintagePort & vp)
{
	if(this==&vp)
		return *this;
	delete [] nickname;
	Port::operator =(vp);//  very important and nasty
	int n=strlen(vp.nickname);
	nickname=new char[n+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}


void VintagePort::Show() const
{
	Port::Show();
	cout<<"nickname: "<<nickname<<endl
		<<"year: "<<year<<endl;
}
