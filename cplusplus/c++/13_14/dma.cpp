#include <iostream>
#include <cstring>
#include "dma.h"
using namespace std;

baseDMA::baseDMA(const char *l,int r)
{
	label=new char[strlen(l)+1];
	strcpy(label,l);
	rating=r;
}

baseDMA::baseDMA(const baseDMA & ra)
{
	label=new char[strlen(ra.label)+1];
	strcpy(label,ra.label);
	rating=ra.rating;
}

baseDMA::~baseDMA()
{
	delete [] label;
}

baseDMA & baseDMA::operator =(const baseDMA & ra)
{
	if(this==&ra)
		return *this;
	delete [] label;
	label=new char [strlen(ra.label)+1];
	strcpy(label,ra.label);
	rating=ra.rating;
	return *this;
}

////////////////////////////////lackDMA methods
lackDMA::lackDMA(const char *c,const char *l,
				 int r):baseDMA(l,r)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

lackDMA::lackDMA(const char * c,const baseDMA & ra):baseDMA(ra)
{
	strncpy(color,c,COL_LEN-1);
	color[COL_LEN-1]='\0';
}

///////////////////////////////hasDMA methods
hasDMA::hasDMA(const char *s,const char *l,int r):baseDMA(l,r)
{
	style=new char[strlen(s)+1];
	strcpy(style,s);
}

hasDMA::hasDMA(const char *s,const baseDMA & ra):baseDMA(ra)
{
	style=new char[strlen(s)+1];
	strcpy(style,s);
}

hasDMA::hasDMA(const hasDMA & hs):baseDMA(hs)
{
	style=new char[strlen(hs.style)+1];
	strcpy(style,hs.style);
}

hasDMA::~hasDMA()
{
	delete [] style;
}

hasDMA & hasDMA::operator =(const hasDMA & ra)
{
	if(this==&ra)
		return *this;
	baseDMA::operator =(ra);
	delete [] style;
	style=new char[strlen(ra.style)+1];
	strcpy(style,ra.style);
	return *this;
}


















