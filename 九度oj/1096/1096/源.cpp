#include <iostream>
using namespace std;

int n1,n2;
struct date
{
	int year,month,day;
};

date d1,d2;

void tran(int num,date & d)
{
	d.day = num % 100;
	num /= 100;
	
	d.month = num % 100;
	num /= 100;

	d.year = num;
}

int day_of_year(int year)
{
	if(year % 100 ==0)
		return year % 400==0 ? 366 : 365;
	return year %4==0 ? 366 : 365;
}

int day_of_month(int month,int year)
{
	if(2==month)
		return day_of_year(year)==366 ? 29 : 28;
	switch(month)
	{
	case 1 :
	case 3 :
	case 5 :
	case 7 :
	case 8 :
	case 10 :
	case 12 :
		return 31;
	default : 
		return 30;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int res = 0;
	while(cin>>n1>>n2)
	{
		res = 0;
		if(n1 > n2)
		{
			int t = n1;
			n1 = n2;
			n2 = t;
		}
		tran(n1,d1);
		tran(n2,d2);
		while(d1.year < d2.year)
		{
			res += day_of_month(d1.month,d1.year) - d1.day;
			d1.month++;
			while(d1.month <= 12)
			{
				res += day_of_month(d1.month,d1.year);
				d1.month++;
			}
			
			d1.month = 1;
			d1.day = 1;
			d1.year++;
			res++;

			while(d1.year < d2.year)
			{
				res += day_of_year(d1.year);
				//res++;
				d1.year++;
			}
		}

		while(d1.month < d2.month)
		{
			res += day_of_month(d1.month,d1.year);
			d1.month++;
		}

		while(d1.day < d2.day)
		{
			res++;
			d1.day++;
		}

		cout<<res + 1<<endl;
	}//cin>>n1>>n2
	return 0;
}