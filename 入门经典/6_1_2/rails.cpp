#include <iostream>
using namespace std;
const int maxn=1000+10;

int main()
{
	int n,p[maxn];
	cin>>n;							//������ĿΪn
	while(n)
	{
		int x,max=0;
		cin>>x;						
		while(x)					//��ջԪ��Ϊx
		{
			memset(p,0,sizeof(p));    //����Ԫ�ؾ�δ��ջ
			bool valid=true;
			for(int i=1;i<=n;i++)
			{
				if(valid)
				{
					bool ok=true;
					for(int j=x+1;j<=max;j++)		//��Ԫ�ر�x��ȴ��Ȼ��ջ�ڣ��򲻳�����max��ջ�кͳ�ջԪ�������ģ�
						if(1==p[j])					//������Ϊmax����n������
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
							p[k]=1;								//��xСȴδ��ջ��Ԫ�� ��Ҫ��ջ
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




