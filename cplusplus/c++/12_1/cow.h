#ifndef COW_H_
#define COW_H_
#include<iostream>
class Cow
{
private:
	enum {NUM=20};
	char name[NUM];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* nm,const char* ho,double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const;
};
#endif



