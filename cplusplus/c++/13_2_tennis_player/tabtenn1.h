#ifndef TABTENN1_H_
#define TABTENN1_H_
#include <iostream>
#include <string>

using namespace std;

class TableTennisPlayer
{
private:
	string firstname;
	string lastname;
	bool hastable;
public:
	TableTennisPlayer(const string & fn="none",
					  const string & ln="none",
					  bool ht=false);
	void name() const;
	bool HasTable() const 
	{
		return hastable;
	}
	void ResetTable(bool v)
	{
		hastable=v;
	}
};

class RatedPlayer :public TableTennisPlayer
{
private:
	unsigned int rating;
public:
	RatedPlayer(unsigned int r=0,
		const string & fn="none",
		const string & ln="none",
		bool ht=false);
	RatedPlayer(unsigned int r,
		const TableTennisPlayer & tp);
	
	unsigned int Rating() const
	{
		return rating;
	}
	void ResetRating(unsigned int r)
	{
		rating=r;
	}
};
#endif


