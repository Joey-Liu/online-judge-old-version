#include <iostream>
const int maxn = 15;
int ans[maxn];
using namespace std;

int main()
{
	freopen("joseph.in","r",stdin);
	freopen("output.txt","w",stdout);
		int n=0;
		int k = 1;
		int r1 = 0,r2 = 0;					//��¼���ַ�ʽ����λ��
		int m1 = 0,m2 = 0;				    //���ֳ��Է�ʽ
		for(k = 1;k <= maxn -1; k++)			//ö��ÿ��k�ĳ���˳��///////////////////////////////////////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		{
			bool ok_1 = true,ok_2 = true;
		//	int m1 = 0,m2 = 0;				//���ֳ��Է�ʽ
			r1 = r2 =0;						//
			int s =1;
			for(s = 1;;s++)							//����һ����ɹ��ǣ��˳�ѭ��
			{
				ok_1 = true;						//ÿ��ѭ����ʼ��Ϊtrue
				ok_2 = true;
				m1= s * (k + 1);
				m2 =s * (k + 1) - k;
				r1 = r2 =0;							//ÿ��ҲҪ��ʼ��������
				int j = 0;
				for(j =0;j < k;j++)				//����k��
				{
					r1 = (r1 + m1 -1)%(2*k - j);
					r2 = (r2 + m2 -1)%(2*k - j);
					if(r1 < k)						//����һ����
					{
						ok_1 = false;
					}
					if(r2 < k)						//����������
					{
						ok_2 = false;
					}
					if(!ok_1 && !ok_2)				//1,2������ʱ��û�б�Ҫ����
					{
						break;
					}
				}
				if(ok_1 || ok_2)					//1 || 2������ȷʱ������ѭ��
				{
					break;
				}
			}
			if(ok_1 && ok_2)
			{
				ans[k] = m1 > m2 ? m2 : m1;
		//		cout<<ans[k]<<endl;
			}
			else if(ok_1)
			{
				ans[k] = m1;
		//		cout<<m1<<endl;
			}
			else if(ok_2)
			{
				ans[k] = m2;
			//	cout<<ans[k]<<endl;
			}
		}
		/*
		for(int i =1;i < maxn -1;i++)
			cout<<ans[i]<<endl;
		*/
		cin>>n;
		while(n)
		{
			cout<<ans[n]<<endl;
			cin>>n;
		}
	system("pause");
	return 0;
}
