#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;

const int maxn = 100000;
int prime[maxn] = {0};
int num_prime = 0;
int isNotPrime[maxn] = {1,1};

int e[maxn];
void prepare()
{
	for(int i = 2;i < maxn;i++)
	{
		if(!isNotPrime[i])
			prime[num_prime++] = i;
		for(int j = 0;j < num_prime && i * prime[j] < maxn;j++)
		{
			isNotPrime[prime[j] * i] = 1;
			if(!(i % prime[j]))
				break;
		}
	}
}

void solve()
{
	string str;
	while(getline(cin,str))
	{
		istringstream ss(str);
		int index = 0;
		while(ss>>e[index])
			index++;
		index--;
		if(index==0 && e[0]==0)
			break;

		int org = 1;
		while(index > 0)
		{
			org *= pow((double)e[index - 1],e[index]);
			index -= 2;
		}

		//memset(e,0,sizeof(e));
		org--;
		index = num_prime - 1;
		int count = 0;
		while(org != 1)
		{
			if(0==org % prime[index])
			{
				count = 0;
				while(0==org % prime[index])
				{
					count++;
					org /= prime[index];
				}
				cout<<prime[index]<<" "<<count<<" ";
			}
			index--;
		}

		cout<<endl;
	}
}

int main()
{
	freopen("primelnd.in","r",stdin);
	freopen("out.txt","w",stdout);
	prepare();
	solve();
	return 0;
}