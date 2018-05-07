#include <iostream>
#include "mytime.h"
using namespace std;

Time::Time()
{
	hours=minutes=0;
}


Time::Time(int h,int m)
{
	hours=h;
	minutes=m;
}


void Time::AddHrs(int h)
{
	hours +=h;
}


void Time::AddMins(int m)
{
	minutes +=m;
	hours=hours+minutes/60;
	minutes=minutes % 60;
}


void Time::Reset(int h,int m)
{
	hours=h;
	minutes=m;
}


Time Time::operator +(const Time & t) const
{
	Time sum;
	sum.hours=hours+t.hours+(minutes+t.minutes) / 60;
	sum.minutes=(minutes+t.minutes) % 60;
	return sum;
}


Time Time::operator -(const Time & t) const
{
	Time diff;
	int tol;
	tol=hours*60 +minutes - t.hours*60-t.minutes;
	diff.hours=tol / 60;
	diff.minutes=tol % 60;
	return diff;
}


Time Time::operator *(double muti) const
{
	Time result;
	int tol=hours*60*muti + minutes*muti;
	result.hours=tol / 60;
	result.minutes=tol % 60;
	return result;
}


void Time::Show() const
{
	cout<<hours<<"hours,"<<minutes<<"minutes";
}



