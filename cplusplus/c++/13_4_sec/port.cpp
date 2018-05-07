#include <iostream>
#include "Port.h"
using namespace std;

Port::Port(const char *br,const char *st,int b)
{
	brand=new char [strlen(br)+1];
	strcpy(brand,br);
	
	strncpy(brand,st,19);
	style[20]='\0';
	bottles=b;
}

Port::Port(const Port & p)
{
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);
	strcpy(style,p.style);
	bottles=p.bottles;
}

Port & Port::operator=(const Port & p)
{
	if(this==&p)
		return *this;
	delete [] brand;
	brand=new char[strlen(p.brand)+1];
	strcpy(brand,p.brand);

	strcpy(style,p.style);
	bottles=p.bottles;
	return *this;
}

Port & Port::operator +=(int b)
{
	bottles+=b;
	return *this;
}

Port & Port::operator -=(int b)
{
	if(bottles>=b)
		bottles-=b;
	else
		cout<<"The number of bottles is not enough.\n";
	return *this;
}

void Port::Show() const 
{
	cout<<"Brand: "<<brand<<endl;
	cout<<"Kind: "<<style<<endl;
	cout<<"Bottles: "<<bottles<<endl;
}
//////////////////////////////派生类方法

VinetagePort::VinetagePort() :Port()
{
	nickname=new char[5];
	strcpy(nickname,"none");
	year=0;
}

VinetagePort::VinetagePort(const char *br,int b,
						   const char *nn,int y): Port(br,"none",b)
{
	nickname=new char[strlen(nn)+1];
	strcpy(nickname,nn);
	year=y;
}

VinetagePort::VinetagePort(const VinetagePort & vp) :Port(vp)
{
	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
}

VinetagePort & VinetagePort::operator =(const VinetagePort & vp)
{
	if(this==&vp)
		return *this;
	Port::operator =(vp);
	nickname=new char[strlen(vp.nickname)+1];
	strcpy(nickname,vp.nickname);
	year=vp.year;
	return *this;
}


void VinetagePort::Show() const
{
	Port::Show();
	cout<<"Nickname: "<<nickname<<endl;
	cout<<"Year: "<<year<<endl;
}



