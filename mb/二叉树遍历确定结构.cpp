#include <iostream>
#include <string>
using namespace std;

string prestr,instr;//��������������

void solve(int prel,int prer,int inl,int inr)
{
	int root,leftsize,rightsize;
	for(root = inl;prestr[prel] != instr[root];root++);//�ҵ���������еĸ�
	leftsize = root - inl;
	rightsize = inr - root;
	if(leftsize > 0)//�������������
	{
		solve(prel + 1,prel + leftsize,inl,inl + leftsize - 1);
	}
	if(rightsize > 0)//�������������
	{
		solve(prel + leftsize + 1,prer,root + 1,inr);
	}
	printf("%c",instr[root]);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>prestr>>instr)
	{
		solve(0,prestr.size() - 1,0,instr.size() - 1);
		printf("\n");
	}
}