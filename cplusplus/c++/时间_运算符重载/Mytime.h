#ifndef MYTIME_H_
#define MYTIME_H_
#include<iostream>

class Time
{
private:
	int hours;
	int minutes;
public:
	//Time()  {hours=0; minutes=0;}		
	Time();
	Time(int h,int m=0);		//���⣬���ܶ�����ΪĬ�ϲ���
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h=0,int m=0);
	
	
	Time operator+(const Time & t) const;
	Time operator-(const Time & t) const;
	Time operator*(double n) const;
	friend Time operator*(double n,Time t)
		{return t*n;}
	friend std::ostream & operator<<(std::ostream & os,const Time & t);			//Σ��
	
	
	void show() const;
};

#endif