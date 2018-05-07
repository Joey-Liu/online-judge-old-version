#include <iostream>
using namespace std;
const int maxn=20 + 5;
int main()
{
	bool exist[maxn];
	memset(exist,false,sizeof(exist));
	int n,k,m;			
	cin>>n>>k>>m;
	while(n || k || m)
	{
		int p=0,q=n+1;
		int left,cnt=0;      //left 在队中的人,cnt计数，即仍然在队列中的人
		while(left)
		{
			int nk=k;			//记录法官1的步长
			while(nk)
			{
				p= p > n ? 1 : p+1;	//寻找第一个计数的人
				while(!exist[p])
				{
					p++;
					p=p > n ? 1: p+1;
					while





