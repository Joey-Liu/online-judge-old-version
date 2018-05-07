#include<iostream>
using namespace std;
int main()
{
    int kn;
    cin>>kn;
    for(int k_i=0;k_i<kn;k_i++)
    {
        int n;
	    cin>>n;
	    while(n)
	    {
		    int ans=0;
		    int j=1;
		    int count=1;
		    for(int i=1;i<=n;)
		    {
		        for(int j=1;j<=count;j++)
		        {
		            ans=ans+count;
                    i++;
				    if(i>n)
					    break;
			    }
			    count++;
			    if(i>n)
				    break;
		    }
		    cout<<n<<" "<<ans<<endl;
		    cin>>n;
	    }
	    if(0==n) break;
	}    
	return 0;
}


