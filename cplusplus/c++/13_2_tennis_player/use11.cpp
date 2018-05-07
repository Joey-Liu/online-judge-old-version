#include <iostream>
#include "tabtenn1.h"
using namespace std;

int main()
{
	TableTennisPlayer player1("Tara","Boomdea",false);
	RatedPlayer rplayer1(1140,"Mallory","Duck",true);

	rplayer1.name();
	if(rplayer1.HasTable())
		cout<<": has a table"<<endl;
	else
		cout<<": does not has a table"<<endl;

	player1.name();
	if(player1.HasTable())
		cout<<": has a table"<<endl;
	else
		cout<<": does not has a table"<<endl;

	cout<<"Name: ";
	rplayer1.name();
	cout<<"Rating: "<<rplayer1.Rating()<<endl;


	RatedPlayer rplayer2(1212,player1);
	cout<<"Name:";
	rplayer2.name();
	cout<<"Rating: "<<rplayer2.Rating()<<endl;

	system("pause");
	return 0;
}
