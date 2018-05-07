#ifndef CD_H_
#define CD_H_
#include <iostream>
using namespace std;

class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char *s1,char *s2,int n,double x);
	Cd();
	virtual void Report() const;
};

class Classic: public Cd
{
private:
	char main_songs[50];
public:
	Classic(char *s1,char *s2,char *s3,int n,double x);
	Classic();
	virtual void Report() const;
};

#endif


