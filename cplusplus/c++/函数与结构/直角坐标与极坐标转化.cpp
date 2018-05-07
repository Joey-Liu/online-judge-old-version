#include<iostream>
#include<math.h>

struct polar
{	
	double distence;
	double angle;
};

struct rect
{
	double x;
	double y;
};

polar rect_to_polar(rect xypos);
void show(polar dapos);
int main()
{
	using namespace std;
    rect rplace;
	polar pplace;


	cout<<"请输入x与y：";
	while(cin>>rplace.x>>rplace.y)
	{
		pplace=rect_to_polar(rplace);
        show(pplace);
		cout<<"下一组数字(按q停止退出):";
	}
	cout<<"Done\n";
	return 0;
}



polar rect_to_polar(rect xypos)
{
	using namespace std;
	polar answer;
	answer.distence=sqrt(xypos.x*xypos.x+xypos.y*xypos.y);
	answer.angle=atan2(xypos.y,xypos.x);
	return answer;
}




void show(polar dapos)
{
	using namespace std;
	double Rad_to_deg=57.29577951;


	cout<<"distence="<<dapos.distence<<endl;
	cout<<"angle="<<dapos.angle*Rad_to_deg<<" degrees\n";
}
