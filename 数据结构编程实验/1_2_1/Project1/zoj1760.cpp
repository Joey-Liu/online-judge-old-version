#include <iostream>
const int num=15 +5;
using namespace std;

int main()
{
//	freopen("fin.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int a[num];
	cin>>a[0];
	while(-1 != a[0])
	{
		int i=1;
		for(i=1;i<num;i++)
		{
			cin>>a[i];
			if(0==a[i])
				break;
		}
		int cnt,k,j=1;
		cnt=0;
		for(k=0;k<i;k++)
		{
			for(j=k+1;j<i;j++)
			{
				if(a[j]==2 * a[k] || a[j] * 2==a[k])
					cnt++;
			}
		}
		cout<<cnt<<endl;
		memset(a,0,num * sizeof(int));
		cin>>a[0];
	}
	//system("pause");
	return 0;
}