#include<cmath>
#include"vector.h"
using namespace std;		//???problem
namespace VECTOR
{
	const double Rad_to_deg=45/atan(1.0);
	
	
	void Vector::set_mag()
	{
		mag=sqrt(x*x+y*y);
	}


	void Vector::set_ang()
	{
		if(0==x&&0==y)
			ang=0;
		else
			ang=atan2(y,x);
	}

	
	void Vector::set_x()
	{
		x=mag*cos(ang);
	}

	
	void Vector::set_y()
	{
		y=mag*sin(ang);
	}


	Vector::Vector()
	{
		x=0.0;
		y=0.0;
		mag=0.0;
		ang=0.0;
		mode=RECT;
	}


	Vector::Vector(double n1,double n2,Mode form)
	{
		if(RECT==form)
		{
			mode=RECT;
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(POL==form)
		{
			mode=POL;
			mag=n1;
			ang=n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else 
		{
			cout<<"the form doesn't exist!\n";
			cout<<"Vect set to 0\n";
			x=y=mag=ang=0.0;
			mode=RECT;
		}
	}



	void Vector::reset(double n1,double n2,Mode form)
	{ 
		if(RECT==form)
		{
			x=n1;
			y=n2;
			set_mag();
			set_ang();
		}
		else if(POL==form)
		{
			mag=n1;
			ang=n2/Rad_to_deg;
			set_x();
			set_y();
		}
		else 
		{
			cout<<"the form doesn't exist!\n";
			cout<<"Vect set to 0\n";
			x=y=mag=ang=0.0;
			mode=RECT;
		}
	}


	Vector::~Vector()
	{
	}

	
	Vector Vector::operator+(const Vector &b) const
	{
		return Vector(x+b.x,y+b.y);
	}


	Vector Vector::operator-(const Vector &b) const
	{
		return Vector(x-b.x,y-b.y);
	}


	Vector Vector::operator-() const		//ÊÇ·ñÊµÏÖ£¿
	{
		return Vector(-x,-y);
	}


	Vector Vector::operator*(double n) const
	{
		return Vector(x*n,y*n);
	}


	ostream & operator<<(ostream & os,const Vector & v)
	{
		if(Vector::RECT==v.mode)
			os<<"(x,y)=("<<v.x<<","<<v.y<<")";
		else if(Vector::POL==v.mode)
			os<<"(m,a)=("<<v.mag<<","<<v.ang*Rad_to_deg<<")";
		else
			os<<"Vector object mode is invaid";
		return os;
	}
}//enf of namespace

















