#include <iostream>
#include <sstream>
#include <string>
using namespace std;
const int maxn = 31;
char TIME_ZONE[][7] = {"GMT","BST","IST","WET","WEST","CET","CEST","EET","EEST",
	"MSK","MSD","AST","ADT","NST","NDT","EST","EDT","CST","CDT","MST","MDT","PST",
	"PDT","HST","AKST","AKDT","AEST","AEDT","ACST","ACDT","AWST","UTC"};
double  time_add[] = {0.0, 1.0, 1.0, 0.0, 1.0, 1.0,2.0, 2.0, 3.0, 3.0, 4.0, -4.0,
	-3.0,-3.5,-2.5,-5.0,-4.0,-6.0,-5.0,-7.0,-6.0,-8.0,-7.0,-10.0,-9.0,-8.0,10.0,
	11.0,9.5,10.5,8.0,0.0};

int main()
{
	int n=0;
	cin>>n;
	cin.get();
	while(n)
	{
	string temp,s_time,s_zone_1,s_zone_2,s_temp;
	getline(cin,temp);
	istringstream ss(temp);

	int hour=0;
	double minute =0.0;
//	bool sign = true;			//true for am,false for pm
	if(ss>>s_temp)
	{
		if("noon"==s_temp || "midnight"==s_temp)
		{
			minute = 0.0;
			hour = ("noon"==s_temp) ? 12 : 0;		//此时采用24小时格式
			ss>>s_zone_1>>s_zone_2;
		}
		else
		{
			int i=0;
			for(i=0;':'!=s_temp[i];i++)
				hour = hour*10 + s_temp[i] - '0';
			for(i++;i < s_temp.size();i++)
				minute = minute*10 + s_temp[i] - '0';
			ss>>s_temp;
			if("p.m."==s_temp && hour != 12)			//有点麻烦
				hour += 12;
			else if("a.m."==s_temp && hour==12)
				hour=0;
			ss>>s_zone_1>>s_zone_2;
		}
		int index_one,index_two;
		for(index_one = 0;index_one < maxn;index_one++)
			if(TIME_ZONE[index_one]==s_zone_1)
				break;
		for(index_two = 0;index_two < maxn;index_two++)
			if(TIME_ZONE[index_two]==s_zone_2)
				break;
		int u_hour=0;
		double u_minute =0.0;
		u_hour = hour - (int)time_add[index_one] + (int)time_add[index_two];
		u_minute = minute - (time_add[index_one] - (int)time_add[index_one])*60 + (time_add[index_two] - (int)time_add[index_two])*60;

		if(u_minute > 60.0)
		{
			u_minute -= 60.0;
			u_hour++;
		}
		else if(u_minute < 0.0)
		{
			u_minute += 60;
			u_hour--;
		}

		if(u_hour >= 24)
			u_hour -= 24;
		else if(u_hour < 0)
			u_hour += 24;
		
		bool flag=true;
		if(12==u_hour && 0.0==u_minute)
		{
			cout<<"noon"<<endl;
			flag=false;
		}
		else if(0==u_hour && 0.0==u_minute)
		{
			cout<<"midnight"<<endl;
			flag=false;
		}
		else if(0==u_hour)
			cout<<"12";
		else
			cout<< (u_hour > 12 ? u_hour - 12 : u_hour)<<":";
		if(flag)
		{
			cout<< (u_minute < 10 ?"0" : "")<<u_minute<<" ";
			cout<< (u_hour > 12 ? "p.m." : "a.m.")<<endl;
		}
	}
	n--;
	}//while
	system("pause");
	return 0;
}
