#include<iostream>
#include<math.h>
#include"coordin.h"

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