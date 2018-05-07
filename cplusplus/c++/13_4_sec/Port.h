#ifndef PORT_H_
#define PORT_H_

#include <iostream>
using namespace std;
class Port
{
private:
	char *brand;
	char style[20];
	int bottles;
public:
	Port(const char *br="null",const char *st="none",int b=0);
	Port(const Port & p);
	virtual ~Port() {delete [] brand;}
	
	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int b);

	int BottleCount() const {return bottles;}
	virtual void Show() const;
	friend ostream & operator<<(ostream & os,const Port & p)
	{
		os<<p.brand<<","<<p.style<<","<<p.bottles;
		return os;
	}
	
};

class VinetagePort :public Port
{
private:
	char *nickname;
	int year;
public:
	VinetagePort();
	VinetagePort(const char *br,int b,const char *nn,int y);
	VinetagePort(const VinetagePort & vp);
	~VinetagePort() {delete [] nickname;}
	VinetagePort & operator=(const VinetagePort & vp);
	virtual void Show() const;
	friend ostream & operator<<(ostream & os,const VinetagePort & vp)
	{
		os<<(const Port &)vp<<",";
		os<<vp.nickname<<","<<vp.year<<".";
		return os;
	}

};

#endif


