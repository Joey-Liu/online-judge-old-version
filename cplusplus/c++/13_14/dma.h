#ifndef DMA_H_
#define DMA_H_
#include <iostream>
using namespace std;

class baseDMA
{
private:
	char *label;
	int rating;
public:
	baseDMA(const char *l="null",int r=0);
	baseDMA(const baseDMA & ra);
	virtual ~baseDMA();
	baseDMA & operator=(const baseDMA & ra);
	friend ostream & operator<<(ostream & os,const baseDMA & ra)
	{
		os<<"Label: "<<ra.label<<endl;
		os<<"Rating "<<ra.rating<<endl;
		return os;
	}
};

class lackDMA: public baseDMA
{
private:
	enum {COL_LEN=40};
	char color[COL_LEN];
public:
	lackDMA(const char * c="blank",const char* l="null",
			int r=0);
	lackDMA(const char * c,const baseDMA & ra);
	friend ostream & operator<<(ostream & os,const lackDMA & ra)
	{
		os<<(const baseDMA &)ra;
		os<<"Color: "<<ra.color<<endl;
		return os;
	}
};

class hasDMA: public baseDMA
{
private:
	char *style;
public:
	hasDMA(const char *s="none",const char *l="null",
		   int r=0);
	hasDMA(const char *s,const baseDMA & ra);
	hasDMA(const hasDMA & hs);
	~hasDMA();
	hasDMA & operator=(const hasDMA & ra);
	friend ostream & operator<<(ostream & os,const hasDMA & ra)
	{
		os<<(const baseDMA &)ra;
		os<<"Style: "<<ra.style<<endl;
		return os;
	}
};

#endif



