#include <iostream>
const unsigned int maxn = 10000 + 100;
using namespace std;

void getnext(char p[],int next[])
{
	long i,j=-1;
	next[0] = -1;
	for(i=0; i < strlen(p) ;)
	{
		while(-1 != j && p[j] !=p[i])
			j = next[j];
		next[i+1] = j+1;
		i++;
		j++;
	}
}

int main()
{
	char p[maxn];
	int num,count=1;
	cin>>num;

	while(num != 0)
	{
		cin.get();
		cin.getline(p,num + 1);
		int next[maxn];
		getnext(p,next);
		
		cout<<"Test case #"<<count<<endl;
		count++;

		int m=2;
		for(m=2; m <= num; m++)
		{

			if(0== m%(m-next[m]) && m != m-next[m] )	//防止产生一个字符串自己循环
				cout<<m<<" "<<m/(m-next[m])<<endl;
		}
		cout<<endl;
		cin>>num;
	}
	system("pause");
}


