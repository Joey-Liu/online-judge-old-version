#include <iostream>
#include <string.h>
using namespace std;

const int size = 26 + 5;
const int maxn = 80 + 20;
int main()
{
	freopen("decode.4.in","r",stdin);
	freopen("ouput4.txt","w",stdout);

	char passwrd[size];
	cin>>passwrd;
	cin.get();
	char str[maxn];
	cin.get(str,maxn);
	int length = strlen(str);

	for(int i = 0;i < length;i++)
	{
		if(' '==str[i])
			cout<<' ';
		else if('a' <= str[i] && 'z' >= str[i])
		{
			cout<<passwrd[str[i] - 'a'];

		}
		else if('A' <= str[i] && 'Z' >= str[i])
		{
			cout<<(char)(passwrd[str[i] - 'A'] - 'a' + 'A');
		}
	}
	return 0;
}
