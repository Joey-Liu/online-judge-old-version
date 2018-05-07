#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include<iostream>
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex();
	Complex(double rval,double ival);
	~Complex() {;}             //此处无用
	Complex operator+(const Complex & b) const;
	Complex operator-(const Complex & b) const;
	Complex operator*(const Complex & b) const;
	friend Complex operator*(double x,const Complex & b);
	friend Complex operator*(const Complex & b,double x)
	{
		return x*b;
	}
	friend Complex operator~(const Complex & b)
	{    
		return Complex(b.real,-b.imaginary);    
	}
    friend std::ostream & operator<<(std::ostream & os,const Complex & b);
	friend std::istream & operator>>(std::istream & is,Complex & b);
	//friend Complex fun(Complex & b);
};
#endif



