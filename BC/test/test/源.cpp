#include <cstdio>
#include<iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include<vector>
#include <time.h>

using namespace std;
const int MAX=100000*2;
const int INF=1e9;

int main()
{
  freopen("in.txt","r",stdin);
  freopen("test.txt","w",stdout);

  int n = 50,m = MAX,ans,i;
    ans=0;
    for(i=1;i<=n;i++)
    {
      if(i&1)
	  {
		  ans=(ans*2+1)%m;
		  cout<<ans<<endl;
	  }
      else
	  {
		  ans=ans*2%m;
		  cout<<ans<<endl;
	  }
    }
  return 0;

  /*  
  srand(time(NULL));
  for(int i = 0;i < 100;i++)
  {
	  int m = (rand() % 100) + 1;
	  if(0==m % 2)
		  cout<<m<<" "<<(rand() % 100) + 1<<endl;
  }
  return 0;
  */
}
