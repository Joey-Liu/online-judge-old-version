#include <iostream>
using namespace std;

const int maxn = 1000 + 200;
int seq[maxn];
int B[maxn];
int len;

int BiSearch(int num)
{
	int lp = 0,rp = len - 1;
	int mid =(lp + rp)/2;

	while(lp + 1 < rp)
	{
		if(B[mid] < num)
			lp = mid;
		else if(B[mid] > num)
			rp = mid;
		else
			return mid;
		mid = (lp + rp)/2;
	}
	if(B[lp] > num)
		return lp;
	else
		return rp;
}

int LIS(int n)//n –Ú¡–≥§∂»
{
	len =1;
	B[0] = seq[0];
	int i,pos = 0;

	for(i = 1;i < n;i++)
	{
		if(seq[i] > B[len -1])
		{
			B[len] = seq[i];
			len++;
		}
		else
		{
			pos = BiSearch(seq[i]);
			B[pos] = seq[i];
		}
	}
	return len;
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int N;
	cin>>N;
	for(int i = 0;i < N;i++)
		cin>>seq[i];
	
	cout<<LIS(N)<<endl;
	return 0;
}