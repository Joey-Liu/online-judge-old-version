#include<iostream>
using namespace std;
const char wstr[][20]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
int day_of_year(int year)
{
	if(year%100==0)
		return year%400==0 ?366:365;
	return year%4==0 ?366:365;
}

int day_of_month(int month,int year)
{
	if(2==month)
		return day_of_year(year)==366 ?29:28;
	switch(month)
	{
	case 1: 
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	default:
		return 30;
	}
}


int main()
{
	long int n;
	cin>>n;
	while(n>=0)
	{
		int year=2000;
		int month,day,week;
		week=n%7;
		month=day=1;
		while(n)
		{
			while(n>=day_of_year(year))
			{
				n=n-day_of_year(year);
				year++;
			}
			while(n>=day_of_month(month,year))
			{
				n=n-day_of_month(month,year);
				month++;
			}
			if(n>0)
				day=day+n;
			n=0;
		}
		cout<<year<<"-"<<(month<10 ?"0":"")<<month<<"-"
			<<(day<10 ?"0":"")<<day<<" "
			<<wstr[week]<<endl;
		cin>>n;
	}
	return 0;
}




Graph <int>