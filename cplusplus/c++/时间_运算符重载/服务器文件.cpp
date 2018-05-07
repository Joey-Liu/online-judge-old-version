#include<iostream>
#include"Mytime.h"

Time::Time()
{
	hours=0;
	minutes=0;
}


Time::Time(int h,int m)
{
	hours=h;
	minutes=m;
}


void Time::AddMin(int m)
{
	hours=hours+(minutes+m)/60;
	minutes=(m+minutes)%60;
}


void Time::AddHr(int h)
{
	hours=hours+h;
}


void Time::Reset(int h,int m)
{
	hours=h;
	minutes=m;
}


Time Time::operator +(const Time & t) const
{
	Time result;
	result.minutes=t.minutes+minutes;
	result.hours=t.hours+hours+result.minutes/60;
	result.minutes=result.minutes%60;
	return result;
}


Time Time::operator -(const Time & t) const
{
	Time one,two,result;
	one.minutes=hours*60+minutes;
	two.minutes=t.hours*60+t.minutes;

	result.minutes=one.minutes-two.minutes;
	result.hours=result.minutes/60;
	result.minutes=result.minutes%60;
	return result;
}


Time Time::operator *(double n) const
{
	Time result;
	result.minutes=hours*60+minutes;
	result.minutes=result.minutes*n;
	result.hours=result.minutes/60;
	result.minutes=result.minutes%60;
	return result;
}



std::ostream & operator<<(std::ostream & os,const Time & t)	
{
	os<<t.hours<<"hours,"<<t.minutes<<"minutes"<<std::endl;
	return os;
}


void Time::show() const
{
	std::cout<<hours<<"hours,"<<minutes<<"minutes.\n";
}
