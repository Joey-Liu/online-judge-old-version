#ifndef CLASSIC_H_
#define CLASSIC_H_
class Cd
{
private:
	enum {FIRST=20,SECOND=50};
	char performers[SECOND];
	char label[FIRST];
	int selections;
	double playtime;
public:
	Cd(char* s1,char* s2,int n,double x);
	Cd(const Cd & d);
	Cd();
	~Cd();
	virtual void Report() const;
	Cd & operator=(const Cd & d);
};


class Classic :public Cd
{
private:
	enum {THIRD=50};
	char major[THIRD];
public:
	Classic(char* c1,char* c2,char* c3,int n,double x);
	Classic(const Classic & cd);
	Classic();
	~Classic();
	virtual void Report() const;
	Classic & operator=(const Classic & cd);
};
#endif


