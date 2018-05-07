#include <iostream>
#include <cstring>
#include "cd.h"
using std::cout;
using std::endl;

Cd::Cd(char *s1,char *s2,int n,double x)
{
	strncpy(performers,s1,49);
	performers[50]='\0';

	strncpy(label,s2,19);
	label[20]='\0';
	selections=n;
	playtime=x;
}

Cd::Cd()
{
	strcpy(performers,"no body");
	strcpy(label,"null");
	selections=0;
	playtime=0.0;
}

void Cd::Report() const
{
	cout<<"Performers: "<<performers<<endl;
	cout<<"Label: "<<label<<endl;
	cout<<"Selections: "<<selections<<endl;
	cout<<"Playtimes: "<<playtime<<" mins\n";
}

Classic::Classic(char *s1,char *s2,char *s3,
				 int n,double x): Cd(s1,s2,n,x)
{
	strncpy(main_songs,s3,49);
	main_songs[50]='\0';
}

Classic::Classic(): Cd()
{
	strcpy(main_songs,"null");
}

void Classic::Report() const
{
	this->Cd::Report();
	cout<<"Main songs: "<<main_songs<<endl;
}


				

