#ifndef PORT_H_
#define PORT_H_
#include<iostream>
using std::endl;
using std::cout;
using std::ostream;


class Port
{
private:
	char* brand;
	enum {SIZE=20};
	char style[SIZE];
	int bottles;
public:
	Port(const char* br="null",const char *st="none",int b=0);
	Port(const Port & p);
	virtual ~Port() {delete [] brand;}
	Port & operator=(const Port & p);
	Port & operator+=(int b);
	Port & operator-=(int b);// may be some problems
	int BottleCount() const
		{return bottles;}
	virtual void Show() const;
	friend ostream & operator<<(ostream & os,const Port & p)
	{
	       os<<p.brand<<", "<<p.style<<", "<<p.bottles;
	       return os;
	}
};



class VintagePort: public Port
{
private:
	char* nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char* br,const char* st,int b,const char* nn,int y);
	VintagePort(const VintagePort & vp);
	virtual ~VintagePort() {delete [] nickname;}
	VintagePort & operator=(const VintagePort & vp);
	virtual void Show() const;
	friend ostream & operator<<(ostream os,const VintagePort & vp)
	{
		os<<(const Port &)vp;
		os<<" ,"<<vp.nickname<<", "<<vp.year;
	}

};
#endif

