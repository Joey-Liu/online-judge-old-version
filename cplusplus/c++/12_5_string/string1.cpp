#include <iostream>
#include "string1.h"
using namespace std;

int String::num_string=0;  //静态成员初始化

String::String(const char* s)
{
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	num_string++;
}


String::String()
{
	len=0;
	str=NULL;
	num_string++;
}


String::String(const String &st)
{
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	num_string++;
}


String::~String()
{
	delete []str;
	num_string--;
}


String & String::operator =(char* s)
{
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	return *this;
}


String & String::operator =(const String &st)
{
	if(this==&st)
		return *this;
	delete []str;
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	return *this;
}


char & String::operator [](int i)
{
	return str[i];
}


const char & String::operator [](int i)  const 
{
	return str[i];
}


int String::Howmany()
{
	return num_string;
}





