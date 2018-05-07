#ifndef COORDIN_H_
#define COORDIN_H_


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
#endif