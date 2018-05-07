#include <iostream>
#include <string.h>
using namespace std;
const int maxn=3000;
const int maxz=20;
struct item
{
	char s[maxz];
	int num;			//记录单词字典顺序
	int cnt;			//记录重复个数
};

int cmp_char(const void* _a,const void* _b)
{
	char* a=(char*)_a;
	char* b=(char*)_b;
	return *a-*b;
}
int cmp_string(const void* _a,const void* _b)
{
	char* a=(char*)_a;
	char* b=(char*)_b;
	return strcmp(a,b);
}

int main()
{
	struct item word[maxn];
	char tmp[maxz];
	while(cin.get(tmp,maxz-1).get())
	{










