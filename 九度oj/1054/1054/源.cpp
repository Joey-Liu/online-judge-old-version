#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn = 200 + 20;
char str[maxn];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>str)
	{
		sort(str,str + strlen(str));
		cout<<str<<endl;
	}
	return 0;
}