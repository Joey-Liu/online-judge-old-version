#include<iostream>
#include<string>
using namespace std;
int main()
{
	string wname;
	int wsol=0;
	int wpt=0;
	string name;
	int sol=0;
	int pt=0;
	int sub=0;
	int time=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		pt=0;
		sol=0;
		cin>>name;
		for(int j=0;j<4;j++)
		{
			cin>>sub;
			cin>>time;
			if(time!=0)
			{
				pt=pt+time+(sub-1)*20;
				sol++;
			}
		}
		if(sol>wsol)
		{
			wname=name;
			wpt=pt;
			wsol=sol;
		}
		else if(sol==wsol&&(pt<wpt))
		{
			wname=name;
			wpt=pt;
			wsol=sol;
	}}
	cout<<wname<<" "<<wsol<<" "<<wpt<<endl;
	return 0;
}
