#include<iostream>
#include"vector.h"
#include<ctime>
#include<cstdlib>
int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0,0.0);
	unsigned long steps=0;
	double target;	  //距离	
	double dstep;    //步长
	cout<<"Enter target distence (q to quit): ";
	while(cin>>target)
	{
		cout<<"Enter step length: ";
		if(!(cin>>dstep))
			break;

		while(result.magval()<target)
		{
			direction=rand()%360;			//伪随机数
			step.reset(dstep,direction,Vector::POL);
			result=result+step;
			steps++;
		}
		cout<<"After "<<steps<<"steps,the subject has the "
			"following location:\n";
		cout<<result<<endl;
		result.polar_mode();
		cout<<"or\n"<<result<<endl;
		cout<<"Average outward distence per step="
		    <<result.magval()/steps<<endl;
		steps=0;
		result.reset(0.0,0.0);
		cout<<"\nEnter target distence (q to qiut): ";
	}
	cout<<"See you\n";
	cin.clear();
	while(cin.get()!='\n')
		continue;
	return 0;
}


