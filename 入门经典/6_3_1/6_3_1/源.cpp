#include <iostream>
#include <math.h>
using namespace std;
const int num = 20;
int s[1<<num];
int main()
{
	int D,I;
	while(cin>>D>>I)
	{
		memset(s,0,sizeof(s));			//���س�ʼʱΪ��
		int k=1,n=(1<<D) - 1;				//nΪ�������
		for(int i=0;i < I;i++ )
		{
			k = 1;						//����1��ʼ���
			for(;;)
			{
				s[k] = !s[k];		//���ط�ת
				k = s[k] ? 2*k : 2*k +1;
				if(k > n)
					break;				//���Ҷ�ӽ��
			}
		}								//�м������ģ��i��С��������̿��صı仯
		cout<<k/2<<endl;			
	}
	system("pause");
	return 0;
}
