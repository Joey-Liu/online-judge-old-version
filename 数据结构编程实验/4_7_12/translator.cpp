#include <iostream>
#include<sstream> 
using namespace std;
const int maxl=20;
const char word[32][20]=
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine",
	"ten",
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
	"hundred",
	"thousand",
	"million",
	"negative"
};

int main()
{
	string line,str;
	while(getline(cin,line))  
    {  
		if(line.length()==0)  
			break;  
		istringstream ss(line);  
		bool b_negative=false;  
		long int num=0;  
		long int pre=0;                                                    //   long long pre=0;  

	    while(ss>>str)
		{
	    	if(str=="negative")
			    b_negative=true;
			int r=0;
			for(r=0;r<32;r++)
				if(word[r]==str)
					break;
			if(r >=0 && r<= 27)                 
			{
				if(r <= 20)
					pre=pre+r;
				else
					pre=pre + (r-18)*10;
			}
			else					//  28 =< r <= 31
			{
				if(28==r)
					pre*=100;
				else if(29==r)
				{
					pre*=1000;
					num+=pre;
					pre=0;
				}
				else if(30==r)
				{
					pre*=1000000;
					num+=pre;
					pre=0;
				}
			}
		}
		num+=pre;
		if(b_negative)  
           num*=-1;  
		cout<<num<<endl;
	}
	return 0;
}
