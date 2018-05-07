#include <iostream>
#include <string>
#include <stdio.h>
#include <memory.h>
using namespace std;
int Num[3][1000];
void Read(int Ord);
void Add();

int main()
{
	int N;
	cin>>N;
	for(N;N;N--)
	{
		memset(Num,0,sizeof(Num));
		Read(0);
		Read(1);
		Add();
	}
	//system("pause");
	return 0;
}

void Read(int Ord)
{
	int flag=0;
	string tmp;
	cin>>tmp;
	for(int i=tmp.length()-1;i>=0;i--)
	{
		Num[Ord][0]++;
		Num[Ord][Num[Ord][0]]=tmp[i]-'0';
	//	cout<<Num[Ord][Num[Ord][0]];
	}
	//cout<<endl<<"·´Ïòºó:\n";
	//cout<<Num[Ord][Num[Ord][0]]<<"  ";
	for(int j=Num[Ord][0];j> Num[Ord][0] /2;j--)
	{
		flag=Num[Ord][j];
		Num[Ord][j]=Num[Ord][Num[Ord][0]-j+1];
		Num[Ord][Num[Ord][0]-j+1]=flag;
	}

	//for(int f=1;f<=Num[Ord][0];f++)
	//	cout<<Num[Ord][f];
	//cout<<endl;

}

void Add()
{
	Num[2][0]= (Num[0][0] > Num[1][0] ? Num[0][0] : Num[1][0]);
	for(int k=1;k<=Num[2][0];k++)
	{
		Num[2][k]+=Num[0][k] + Num[1][k];
		if(Num[2][k]>9)
		{
			Num[2][k]=Num[2][k] - 10;
			Num[2][k+1]++;
		//	cout<<"Yo\n";
		//	cout<<k<<":"<<Num[2][k+1]<<endl;
		}
	}
	if(Num[2][ Num[2][0]+1 ] > 0)
		Num[2][0]++;
	int flag=0;
	for(int i=1;i<=Num[2][0];i++)
	{
		if(Num[2][i]>0)
			flag=1;
		if(1==flag)
			cout<<Num[2][i];
	}
	cout<<endl;
	//memset(Num,0,sizeof(Num));
}
