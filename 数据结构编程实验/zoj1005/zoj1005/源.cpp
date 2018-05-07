#include <iostream>
using namespace std;

int main()
{
	int a,b,g;
	while(scanf("%d%d%d",&a,&b,&g) != EOF)
	{
		int bottle1 = 0,bottle2 = 0;
		while(true)
		{
			if(bottle1==0)
			{
				bottle1 = a;
				printf("fill A\n");
			}
			if(bottle1 + bottle2 <= b)
			{
				bottle2 += bottle1;
				bottle1 = 0;
				printf("pour A B\n");
			}
			else
			{
				bottle1 = (bottle1 + bottle2 - b);
				bottle2 = bottle1;
				bottle1 = 0;
				printf("pour A B\nempty B\npourA B\n");
			}
			if(bottle2 == g)
			{
				printf("success\n");
				break;
			}
		}//while(true)

	}//while
}