#include <iostream>
using namespace std;
const int maxn=1000+10;

int main()
{
	int n,p[maxn];
	cin>>n;							//车厢数目为n
	while(n)
	{
		int x,max=0;
		cin>>x;						
		while(x)					//出栈元素为x
		{
			memset(p,0,sizeof(p));    //所有元素均未进栈
			bool valid=true;
			for(int i=1;i<=n;i++)
			{
				if(valid)
				{
					bool ok=true;
					for(int j=x+1;j<=max;j++)		//若元素比x大，却依然在栈内，则不成立（max是栈中和出栈元素中最大的）
						if(1==p[j])					//个人认为max可用n来代替
						{
							ok=false;
							break;
						}
					if(!ok)
						valid=false;
					else
					{
						max=(max > x ? max:x);
						p[x]=2;
						for(int k=x-1;(k>0) && (!p[k]);k--)
							p[k]=1;								//比x小却未入栈的元素 均要入栈
					}
				}
				if(i<n)
					cin>>x;
			}
			cout<<(valid ? "Yes" : "No")<<endl;
			cin>>x;
		}
		cout<<endl;
		cin>>n;
	}
//	system("pause");
	return 0;
}




