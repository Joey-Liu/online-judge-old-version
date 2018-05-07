#ifndef STRING1
#define STRING1
#include <iostream>
using namespace std;

class String
{
private:
	char* str;
	int len;
	static int num_string;
	enum { CINLIM=81 };
public:
	String(const char* s);
	String();
	String(const String &);
	~String();
	
	int lengh() const 
	{
		return len;
	}
	
	String & operator=(char* s);		//�������εȺ�
	String & operator=(const String &);
	char & operator[](int i);
	const char & operator[](int i) const;	//maybe have a problem 
	
	/////////////////////////////////////////��Ԫ�������˰汾�ֿ���������
    friend bool operator< (const String &st1,const String &st2)
	{
		return (strcmp(st1.str,st2.str) < 0);
	}


	friend bool operator> (const String &st1,const String &st2)
	{
		return (strcmp(st1.str,st2.str) > 0);
	}


	
	friend bool operator== (const String &st1,const String &st2)
	{
		return (0==strcmp(st1.str,st2.str));
	}


	friend ostream & operator<< (ostream & os, const String &st)
	{
		os<<st.str;
		return os;
	}

	friend istream & operator>> (istream & is, String &st)
	{
		char temp[CINLIM];
		is.get(temp,CINLIM);
		if(is)
			st=temp;
		while('\n'!=is.get() && is)
			continue;
		return is;
	}


	/////////////////////////////////////////��̬����
	static int Howmany();
};
#endif
