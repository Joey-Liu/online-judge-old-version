#ifndef PERSON_H_
#define PERSON_H_


using namespace std;
class Person
{
private:
	enum {LIMIT=25};
	string lname;
	char fname[LIMIT];
public:
	Person() {lname="no name";fname[0]='\0';}
	Person(const string &ln,const char *fn="Heyyou");
	void show() const;
	void FomalShow() const;
};


#endif
