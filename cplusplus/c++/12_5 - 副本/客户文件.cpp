#include<iostream>
#include"queue.h"
#include<cstdlib>	//for rand()or srand()
#include<ctime>		//for time()
using namespace std;

const int MIN_PER_HR=60;

bool newcustomer(double x);


int main()
{
	srand(time(0));

	cout<<"Case Study:Bank of Heather Automatic Teller\n";
	cout<<"Enter maximum size of queue: ";
	int gs;
	cin>>gs;
	Queue line(gs);

	
	cout<<"Enter the number of simulation hours: ";
	int hours;
	cin>>hours;
	long cyclelimit=hours*MIN_PER_HR;


	/*cout<<"Enter the average number of customers per hour: ";
	double perhour;
	cin>>perhour;*/
	double min_per_cust=0;	//time between arrivals;
	//min_per_cust=MIN_PER_HR/perhour;


	Item temp;	//defined in .h file
	long turnaways=0;		//refused customers
	long customers=0;		//joined the queue
	long served=0;			//served during the simulation
	long sum_line=0;		//每分钟的队长
	int wait_time=0;		//time until teller is free
	long line_wait=0;		//all people's time in line
	long max=0;
	int i=1;
	int y=0;
for(i=1;i<130;i++)
{
	min_per_cust=MIN_PER_HR/i;	
	for(double cycle=0;cycle<cyclelimit;cycle++)		//now running the simulation
	{
		//cout<<"."<<endl;
		if(newcustomer(min_per_cust))
		{
			//cout<<"1"<<endl;
			if(line.isfull())
			{
				//cout<<"1.1\n";
				turnaways++;
			}
			else
			{
				//cout<<"1.2\n";
				temp.set(cycle);
				line.enqueue(temp);
				customers++;
			}
		}
		//cout<<"1!\n";
		if(wait_time<=0&&!(line.isempty()))		//前一位顾客结束，而且后面仍有顾客
		{
			//cout<<"2\n";
			line.dequeue(temp);
			wait_time=temp.ptime();
			line_wait=line_wait+cycle-temp.when();
			served++;
		}
		//cout<<"2!\n";
		if(wait_time>0)
		{
			//cout<<"3\n";
			wait_time--;
		}
		//cout<<"3!\n";
		sum_line=sum_line+line.queuecount();
		//cout<<"!?\n";
	}//end of second for

	if((double) line_wait/served<1)
	{
	  /*if(customers>0)
	  {
		cout<<"customers accepted: "<<customers<<endl;
		cout<<"  customers served: "<<served<<endl;
		cout<<"         turnaways: "<<turnaways<<endl;
		cout<<"average queue size: ";
		cout.precision(2);
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"average waiting time: "
			<<(double) line_wait/served<<" minutes\n";
	  }
	  else
		cout<<"No customers...\n";*/
		y++;
		cout<<(double) line_wait/served<<"\n";
		if(i>max)
			max=i;
	}
	
}//end of first for

	cout<<"MAX: "<<max<<endl;
	cout<<"Y: "<<y<<endl;
	cout<<"Done!\n";

	getchar();
	return 0;
}



//x is the time between two customers
bool newcustomer(double x)
{
	return (rand()*x/RAND_MAX<1);
}



































