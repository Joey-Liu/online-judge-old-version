#include<iostream>
#include "complex0.h"
using namespace std;

Complex::Complex()
{
    real =imaginary=0.0;
}



Complex::Complex(double rval,double ival)
{
	real=rval;
	imaginary=ival;
}


Complex Complex::operator+(const Complex & b) const
{
	Complex result;
	result.real=real+b.real;
	result.imaginary=imaginary+b.imaginary;
	return result;
}


Complex Complex::operator-(const Complex & b) const
{
	Complex result;
	result.real=real-b.real;
	result.imaginary=imaginary-b.imaginary;
	return result;
}


Complex Complex::operator*(const Complex & b) const
{
	return Complex(real*b.real-imaginary*b.imaginary,real*b.imaginary+imaginary*b.real);
}


Complex operator*(double x,const Complex & b)
{
	return Complex(x*b.real,x*b.imaginary);
}


std::ostream & operator<<(std::ostream & os,const Complex & b)
{
	os<<"("<<b.real<<","<<b.imaginary<<"i)";
	return os;
}


std::istream & operator>>(std::istream & is,Complex & b)
//有瑕疵，输入错误时的返回值
{
	cout<<"real:";
	if(is>>b.real)
	{
	   cout<<"imaginary:";
	   is>>b.imaginary;
	}
	return is;
}


/*Complex fun(Complex & b)
{
	b.imaginary++;
	b.real++;
	return b;
}*/
