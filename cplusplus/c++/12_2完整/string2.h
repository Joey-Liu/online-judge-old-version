#ifndef STRING2_H_
#define STRING2_H_
#include<iostream>
//using namespace std;       尽量不要使用该using编译，否则友元函数无法访问私有成员
using std::ostream;
using std::istream;
class String2
{
private:
	char* str;
	int len;
	static int num_strings;
	enum {CLIMIT=80};			//输入限制
public:
	String2(const char* s);
	String2();
	String2(const String2 & st);
	~String2();
	int length() const {return len;}
	String2 & operator=(const String2 &);
	String2 & operator=(const char* s);
	char & operator[](int i);
	const char & operator[](int i) const;
	friend bool operator<(const String2 & st,const String2 & st2);
	friend bool operator>(const String2 & st,const String2 & st2);
	friend bool operator==(const String2 & st,const String2 & st2);
	friend ostream & operator<<(ostream & os,const String2 & st);
	friend istream & operator>>(istream & is,String2 & st);
	static int Howmany()
	{
		return num_strings;
	}
	friend String2 operator+(const String2 & st,const String2 & st2);
	void Stringlow();
	void Stringup();
	int has(const char c);
};
#endif