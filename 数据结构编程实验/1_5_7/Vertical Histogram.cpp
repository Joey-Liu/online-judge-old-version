#include<iostream>
#include<string.h>
#include<fstream>
const int SIZE=80;
using namespace std;
int main()
{
	ifstream inFile;
	inFile.open("test.txt");
	if(!inFile.is_open())
	{
		cout<<"Could't open the file\n";
		cout<<"Program is over...\n";
		exit(0);
	}
	char temp[SIZE];
	//string temp;
	int cnt[26]={0};


	inFile.get(temp,80);
	int num=strlen(temp);
	int filein=0;
  for(filein=0;filein<4;filein++)
  {
	for(int cnum=0;cnum<num;cnum++)
	{
		if(temp[cnum]>=65&&temp[cnum]<=90)
			cnt[temp[cnum]-'A']++;
	}
	//inFile.clear();
	while(inFile.get()!='\n')
	    continue;
	inFile.get(temp,80);				//is a problem
	int num=strlen(temp);
  }

	for(int test=0;test<26;test++)
		cout<<cnt[test]<<" ";
	cout<<endl;
	int maxc=0;
	int limit=0;
	int i_1=0;
	for(i_1=0;i_1<26;i_1++)
		if(maxc<cnt[i_1])
			maxc=cnt[i_1];
 	//cout<<"MAX: "<<maxc<<endl;

	for(int i=0;i<maxc;i++)
	{
		int k;
		for(k=25;k>=0;k--)
		{
			if(cnt[k]>=maxc-i)				//
			{
				limit=k;
				break;
			}
		}
		int j;
		for(j=0;j<=limit;j++)
		{
			if(cnt[j]>=maxc-i)			//
				cout<<"* ";
			else
				cout<<"  ";
		}
		cout<<endl;
	}
	char c;
	for(c='A';c<=90;c++)
		cout<<c<<" ";
	cout<<endl;
	return 0;
}




	