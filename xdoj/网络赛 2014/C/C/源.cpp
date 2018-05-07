///////23:30 zhi 23:20
#include <iostream>
using namespace std;

int caculate(int begin_hr,int begin_min,int end_hr,int end_min)
{
	if(end_hr - begin_hr > 0 || (end_min >= begin_min) &&(end_hr - begin_hr == 0) )//Í¬Ò»Ìì
		return (end_hr - begin_hr) * 60 +(end_min - begin_min);
	else// if(end_hr - begin_hr < 0)
	{
		int time_1 = (24 - begin_hr) * 60 - begin_min;
		int time_2 = end_hr * 60 + end_min;
		return time_1 + time_2;
	}
}

int main()
{
	int be_hr,be_min,en_hr,en_min;
	char tc;
	while(cin>>be_hr)
	{
		cin>>tc>>be_min;
		cin>>en_hr>>tc>>en_min;

		int result = caculate(be_hr,be_min,en_hr,en_min);
		cout<<result<<endl;
	}
	return 0;
}
