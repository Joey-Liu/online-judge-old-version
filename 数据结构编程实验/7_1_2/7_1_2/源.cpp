#include <iostream>
#include <algorithm>

using namespace std;
const int maxn = 10000 + 100;
int a[maxn],n;

int main()
{
	cin>>n;
	for(int i = 1;i <= n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[(n + 1) / 2]<<endl;
	system("pause");
	return 0;
}
