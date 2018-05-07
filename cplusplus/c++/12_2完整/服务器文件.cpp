#include<iostream>
#include<string.h>
#include"string2.h"
#define LIMIT 80
using namespace std;

int String2::num_strings=0;


String2::String2(const char* s)
{
	len=strlen(s);
	str=new char[len+1];
	strcpy(str,s);
	num_strings++;
}


String2::String2()
{
	str=NULL;
	len=0;
	num_strings++;
}


String2::String2(const String2 & st)
{
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	num_strings++;
}


String2::~String2()
{
	num_strings--;
	delete []str;
}


String2 & String2::operator=(const String2 & st)
{
	if(this==&st)
		return *this;
	delete []str;
	len=st.len;
	str=new char[len+1];
	strcpy(str,st.str);
	return *this;
}


String2 & String2::operator=(const char* s)
{
	delete []str;
	str=new char[strlen(s)+1];
	strcpy(str,s);
	len=strlen(s);
	return *this;
}



char & String2::operator[](int i)
{
	return str[i];
}


const char & String2::operator[](int i) const
{
	return str[i];
}


bool operator<(const String2 & st,const String2 & st2)
{
	int i,j=0;
	i=st.len>st2.len?st2.len:st.len;
	for(;j<=i;j++)					//j=0时，其中一个ASCII为0
	{
		if(st.str[j]<st2.str[j])
			return true;
		else if(st.str[j]>st2.str[j])
			return false;
	}
	return false;
}



bool operator>(const String2 & st,const String2 & st2)
{
	return (st2<st);
}


bool operator==(const String2 & st,const String2 & st2)
{
	if(st.len!=st2.len)
		return false;
	int i=st.len;
	for(int j=0;j<i;j++)
	{
		if(st.str[j]!=st2.str[j])
			return false;
	}
	return true;
}



ostream & operator<<(ostream & os,const String2 & st)
{
	os<<st.str;
	return os;
}



istream & operator>>(istream & is,String2 & st)
{
	char temp[LIMIT];
	is.get(temp,LIMIT);
	if(is)
		st=temp;
	while(is&&is.get()!='\n')
		continue;
	return is;
}


String2 operator+(const String2 & st,const String2 & st2)
{
	int i=0;
	int j=0;
	String2 result;
	result.len=st.len+st2.len;
	result.str=new char[result.len+1];
	for(;i<st.len;i++)
		result.str[i]=st.str[i];
	for(;i<result.len;i++,j++)
		result.str[i]=st2.str[j];
	result.str[i]='\0';
	return result;
}



void String2::Stringlow()
{
	int i=0;
	for(;i<len;i++)
	{
		if(str[i]>=65&&str[i]<=90)
			str[i]=str[i]+32;
	}
}



void String2::Stringup()
{
	int i=0;
	for(;i<len;i++)
	{
		if(str[i]>=97&&str[i]<=122)
			str[i]=str[i]-32;
	}
}



int String2::has(const char c)
{
	int i,count=0;
	for(i=0;i<len;i++)
	{
		if(c==str[i])
			count++;
	}
	return count;
}













