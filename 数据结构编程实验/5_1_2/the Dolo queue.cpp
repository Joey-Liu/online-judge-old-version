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
		int left,cnt=0;      //left �ڶ��е���,cnt����������Ȼ�ڶ����е���
		while(left)
		{
			int nk=k;			//��¼����1�Ĳ���
			while(nk)
			{
				p= p > n ? 1 : p+1;	//Ѱ�ҵ�һ����������
				while(!exist[p])
				{
					p++;
					p=p > n ? 1: p+1;
					while





