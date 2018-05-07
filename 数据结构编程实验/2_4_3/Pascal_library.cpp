#include <iostream>
#define STU_SIZE 100
using namespace std;

int main()
{
	int stu[STU_SIZE],temp[STU_SIZE];
	memset(stu,1,STU_SIZE);
	memset(temp,1,STU_SIZE);

	int nd,num_stu;
	cin>>num_stu>>nd;
	
	while(0!=num_stu && 0!=nd)
	{

	    for(;nd>0;nd--)
		{
		    for(int i=0;i<num_stu;i++)
			{
			    cin>>stu[i];
			    stu[i]=stu[i] & temp[i];
				temp[i]=stu[i];
			}
		}

		bool flag=0;
		for(int i=0;i<num_stu;i++)
			if(1==stu[i])
			{
				flag=true;
				break;
			}
		if(true==flag)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		
		cin>>num_stu>>nd;
	}
	return 0;
}


			
