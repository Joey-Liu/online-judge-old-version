#include"move.h"
#include<iostream>
using std::cout;
using std::endl;

Move::Move(double a,double b)
{
	x=a;
	y=b;
}

void Move::showmove() const
{
	cout<<"x="<<x<<","
		<<"y="<<y<<endl;
}


Move Move::add(const Move & m) const
{
	Move result;
	result.x=x+m.x;
	result.y=y+m.y;
	return result;
}


void Move::reset(double a,double b)
{
	x=a;
	y=b;
}


