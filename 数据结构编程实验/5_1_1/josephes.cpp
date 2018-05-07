#include <iostream>
#include <string>
using namespace std;
const int maxn=64 + 5; 

int main()
{
	int n,i=0;
	string name[maxn];
	int p[maxn];
	char c;

	cin>>n;
	for(i=0;i<n;i++)
		cin>>name[i];
	for(i=0;i<n;i++)
		p[i]=i;
	int w,s;
	cin>>w>>c>>s;

	w=w-1;				//第一个人报数初始化
	while(n)
	{
		w=(w + s -1) % n;
		cout<<name[p[w]]<<endl;
		for(i=w;i<n-1;i++)
			p[i]=p[i+1];
		n--;
	}
	return 0;
}






	
