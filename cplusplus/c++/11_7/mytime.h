#ifndef MYTIME_H_
#define MYTIME_H_
#include <iostream>

using namespace std;
class Time
{
private:
	int hours;
	int minutes;
public:
	Time();
	Time(int h,int m=0);
	void AddHrs(int h);
	void AddMins(int m);
	void Reset(int h,int m);
	Time operator +(const Time & t) const;
	Time operator -(const Time & t) const;
	
	Time operator *(double muti ) const;
	friend Time operator *(double muti, const Time & t)
	{
		return t*muti;
	}

	friend ostream & operator <<(ostream & os,const Time & t)
	{
		os<<t.hours<<"hours,"<<t.minutes<<"minutes";
		return os;
	}

	void Show() const;
};
#endif

