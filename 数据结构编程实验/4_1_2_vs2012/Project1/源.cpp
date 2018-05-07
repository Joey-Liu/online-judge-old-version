#include <iostream>
using namespace std;
bool isOld(int month,int day,int year)
{
	if(year < 1752 || (1752==year && month < 9) || (1752==year && 9==month && day <= 2))
		return true;
	return false;
}

bool isLeap(int year,bool old)
{
	if(old)
		return (0==year % 4 ? true : false);
	else
	{
		if(0==year%4 && 0 != year%100)
			return true;
		else if(0==year%400)
			return true;
		else
			return false;
	}
	
}

int day_of_year(int year,bool old)
{
	return (true==isLeap(year,old)) ? 366 : 365;
}

int days_of_month(int month,int year,bool old)
{
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
	case 2:
		if(isLeap(year,old))
			return 29;
		else
			return 28;
	default :
		return 30;
	}
}

bool Isvalid(int month,int day,int year,bool old)
{
	if(1752==year && 9==month && 3 <= day && day <=13)
		return false;
	else if(year < 1)
		return false;
	else if(month < 1 || month > 12)
		return false;
	else if(day > days_of_month(month,year,old) || day < 1)
		return false;
	return true;
}
const int maxn = 15;
const char wstr[][maxn]={"Sunday","Monday","Tuesday","Wendnesday","Thursday","Friday","Saturday"};
const char mstr[][maxn]={"","January","February","March","April","May","June","July",
	"August","September","October","November","December"};

int main()
{
	int month,day,year;
	bool old,valid;
	cin>>month>>day>>year;
	while(month || day || year)
	{
		old = isOld(month,day,year);
		valid = Isvalid(month,day,year,old);
		if(!valid)
		{
			cout<<month<<'/'<<day<<'/'<<year<<" is an invalid date.\n";
			cin>>month>>day>>year;
			continue;
		}
		long sum = 0;
		for(int yy = 1; yy < year;yy++)
			sum += day_of_year(yy,old);			//这个地方有点不懂
		for(int mm = 1;mm < month;mm++)
			sum += days_of_month(mm,year,old);
		sum += day;

		sum = sum%7;
		if(!old)
			cout<<mstr[month]<<" "<<day<<","<<year<<" is a "<<wstr[sum]<<endl;
		else
			cout<<mstr[month]<<" "<<day<<","<<year<<" is a "<<wstr[(sum+5)%7]<<endl;
		cin>>month>>day>>year;
	}
	system("pause");
	return 0;
}
