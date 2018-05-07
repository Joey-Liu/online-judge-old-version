#include <iostream>
#include <string>
#include <sstream>
const int maxn = 100 + 20;

bool val[maxn];
int op[maxn], vtop,otop;					//���������ֵջ��ָ��

using namespace std;

void cal()								//�Ѿ����������ջ���������ջ
{
	bool a = val[--vtop];
	if(3==op[otop - 1])
	{
		a = !a;
		val[vtop++] = a;
		otop--;
	}
	else if(2==op[otop - 1])
	{
		int b = val[--vtop];
		val[vtop++] = a && b;
		otop--;
	}
	else if(1==op[otop - 1])
	{
		int b = val[--vtop];
		val[vtop++] = a || b;
		otop--;
	}
}

int main()
{
	freopen("BooleanExp.in","r",stdin);
	freopen("output.txt","w",stdout);
	int loop =0;
	char c;
	string s;

	while(getline(cin,s))
	{
		istringstream ss(s);
		ss>>c;
		vtop = otop = 0;		//ָ���ʼ��
		do 
		{
				if('('==c)
				{
					op[otop++] = 0;
				}
				else if(')'==c)
				{
					while(0 != op[otop - 1])				//////////////////////////////
						cal();
					otop--;
				}
				else if('!'==c)
				{
					op[otop++] = 3;
				}
				else if('&'==c)
				{
					while(op[otop - 1] >= 2)				//////////////////////////////
						cal();
					op[otop++] = 2;
				}	
				else if('|'==c)
				{
					while(op[otop - 1] >= 1)			//////////////////////////////
						cal();
					op[otop++] = 1;
				}
				else if('V'==c || 'F'==c)
				{
					if('V'==c)
						val[vtop++] = 1;
					else
						val[vtop++] = 0;
				}
		}while(ss>>c);
		while(otop > 0)							//���������ʣ��
			cal();
		if(true==val[vtop - 1])				//��ʱvtopӦ��Ϊ1
			cout<<"Expression "<<loop + 1<<": V\n";
		else
			cout<<"Expression "<<loop + 1<<": F\n";
		loop++;
	}
	//system("pause");
	return 0;
}
