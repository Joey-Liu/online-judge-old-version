#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include<algorithm>
#include <math.h>
#include <memory.h>

using namespace std;
map<string, string> i2bin;
map<string, string> bin2i;

void init()
{
	i2bin["ADD"] = "000001";
	i2bin["SUB"] = "000010";
	i2bin["DIV"] = "000011";
	i2bin["MUL"] = "000100";
	i2bin["MOVE"] = "000101";
	i2bin["SET"] = "000110";

	bin2i["000001"] = "ADD";
	bin2i["000010"] = "SUB";
	bin2i["000011"] = "DIV";
	bin2i["000100"] = "MUL";
	bin2i["000101"] = "MOVE";
	bin2i["000110"] = "SET";
}

char mod;
const int maxn = 30;
char str[maxn],s1[maxn],s2[maxn];
int arr[5];

void trans(int num)
{
	memset(arr,0,sizeof(arr));
	int index = 4;
	while(num != 0)
	{
		arr[index] = num % 2;
		num /= 2;
		index--;
	}
	for(int i = 0;i < 5;i++)
		printf("%d",arr[i]);
}

void solve_i2bin()
{
	printf("%s",i2bin[s1].data());
	int a,b;

	a = s2[1] - '0';
	if(s2[2] != ',')
	{
		a *= 10;
		a += s2[2] - '0';
	}

	if(0==strcmp(s1,"SET"))
	{
		trans(a);
		printf("00000\n");
		return;
	}

	b = s2[strlen(s2) - 1] - '0';
	if('R' != s2[strlen(s2) - 2])
		b = b + (s2[strlen(s2) - 2] - '0') * 10;
	
	trans(a);
	trans(b);
	printf("\n");
}

int transform(char s[])
{
	int res = 0,po = 1;
	for(int i = 4;i >= 0;i--)
	{
		res  = res + (*(s + i) - '0') * po;
		po *= 2;
	}
	return res;
}

void solve_bin2i()
{
	string res,tmp;
	for(int i = 0;i < 6;i++)
		tmp += str[i];
	bool flag = false;

	for(map<string,string>::iterator it = i2bin.begin();it != i2bin.end();it++)
	{
		if((*it).second==tmp)
		{
			res += (*it).first;
			flag = true;
			break;
		}
	}
	if(!flag)
	{
		printf("Error!\n");
		return;
	}

	res += ' ';
	if("SET "==res)
	{
		if(0 != strcmp("00000",str + 11))
		{
			printf("Error!\n");
			return;
		}
		int num = transform(str + 6);
		cout<<res<<"R"<<num<<endl;
	}
	else
	{
		int a = transform(str + 6);
		int b = transform(str + 11);
		cout<<res<<"R"<<a<<","<<"R"<<b<<endl;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	init();

	while(EOF != scanf("%c",&mod))
	{
		if('1'==mod)
		{
			scanf("%s",s1);
			scanf("%s",s2);
			solve_i2bin();
		}
		else
		{
			scanf("%s",str);
			solve_bin2i();
		}
		getchar();
	}
	return 0;
}