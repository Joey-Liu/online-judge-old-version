#include<iostream>
#include<string>
using namespace std;
bool isleap(int year)
{
	if(year%100==0)
		return 0==year%400 ?true:false;
	return 0==year%4 ?true:false;
}

int day_of_month(int month,int year)
{
	if(2==month)
		return isleap(year) ?29:28;
	switch(month)
	{
	case 0:									//just for 1 to 12

	  case 1: case 3: case 5: case 7: case 8: case 10:
	  case 12: return 31;
	  default: return 30;
	}
}

int week;
const char* wstr[7]={"SUN","MON","TUE","WED","THU","FRI",
					  "SAT"};
int year,month,day;
const string mstr[13]={"","JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC"};

int zt;
const string zstr[6]={"UT","GMT","EDT","CDT","MDT","PDT"};
const int d[6]={1,3,7,8,9,10};

int hour,minutes,second,dh,dm;
int main()
{
	char cw[4],ct;		//cw for week day,ct for , :
	string imonth;		//for char 
	string szt;
	for(int i=0;i<3;i++)
		cin>>cw[i];
	cw[3]='\0';
	cin>>ct;

	cin>>day>>imonth>>year;
	
	cin>>hour;
	cin.get(ct);
	cin>>minutes;
	cin.get(ct);
	cin>>second;

	cin>>szt;
	string wtemp=cw;
	//cout<<"test:"<<cw<<endl;
	//cout<<wtemp<<endl;
	/*if(0==strcmp(cw,wstr[0]))
		cout<<"something wrong I don't know...\n";
	else
		cout<<"Damn!\n";*/
	for(week=0;week<7;week++)
		if(0==strcmp(wstr[week],cw))
			break;			//convert week
	if(year<1900)
		year+=1900;
	for(month=1;month<=12;month++)
		if(mstr[month]==imonth)
		{	cout<<month<<endl;
			break;				//convert month
		}
	zt=0;
	for(;zt<6;zt++)
		if(zstr[zt]==szt)
			break;
	dh=dm=0;
	if(zt>=6)
	{
		for(int i=1;i<3;i++)
			dh=dh*10+szt[i]-'0';
		for(int j=3;j<5;j++)
			dm=dm*10+szt[j]-'0';
		if(szt[0]=='+')
		{
			dh=-dh;
			dm=-dm;
		}
		hour=hour+dh+3;
		minutes=minutes+dm;
	}
	else
		hour=hour+d[zt];
	
	
	if(minutes<0)
	{
		minutes+=60;
		hour--;
	}
	else if(minutes>=60)
	{
		minutes-=60;
		hour++;
	}

	if(hour<0)
	{
		hour+=24;
		week=(week-1+7)%7;
		day--;
	}
	else if(hour>=24)
	{
		hour-=24;
		week=(week+1)%7;
		day++;
	}

	if(day<=0)
	{	
		day=day_of_month(month-1,year);
		--month;
	}
	else if(day>day_of_month(month,year))
	{
		day=1;
		month++;
	}

	if(month<1)
	{
		month=12;
		year--;
	}
	else if(month>12)
	{
		month=1;
		year++;
	}
	cout<<wstr[week]<<","<<(day<10?"0":"")
		<<day<<" ";
	cout<<mstr[month]<<" "<<year<<" ";
	cout<<(hour<10?"0":"")<<hour<<":"<<(minutes<10?"0":"")<<minutes<<":"<<(second<10?"0":"")<<second<<" ";
	//cout<<szt;				//problems
	/*if(zt<6)
	{
		cout<<"+";
		if(zt!=5)
			cout<<"0";
		cout<<d[zt]<<"00";
	}
	else
		cout<<szt;*/
	cout<<"+0300";
	cout<<endl;
	return 0;
}








