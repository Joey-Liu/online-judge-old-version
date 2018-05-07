#include "studentc.h"
#include <iostream>
using namespace std;

double Student::Average() const
{
	if(scores.size()>0)
		return scores.sum()/scores.size();
	else
		return 0.0;
}

const string & Student::Name() const
{
	return name;
}

double & Student::operator[] (int i)
{
	return scores[i];
}

double Student::operator [] (int i) const 
{
	return scores[i];
}

///////私有成员函数
ostream & Student::arr_out(ostream & os) const
{
	int limit=scores.size();
	if(limit>0)
	{

		for(int i=0;i<limit;i++)
		{
			os<<scores[i]<<" ";
			if(4==i%5)
				os<<endl;
		}
	}
	else
		os<<" empty line.";
	return os;
}




