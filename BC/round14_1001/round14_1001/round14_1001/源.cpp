#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <memory.h>
#include <vector>

typedef long long LL;

using namespace std;
int v,v0;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	while(cin>>v>>v0)
		cout<<(-v0 + 2 * v)<<endl;
	return 0;
}