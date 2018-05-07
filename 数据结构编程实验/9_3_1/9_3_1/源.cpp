#include <iostream>
#include <string>
using namespace std;

string prestr,instr;//先序，中序遍历结果

void solve(int prel,int prer,int inl,int inr)
{
	int root,leftsize,rightsize;
	for(root = inl;prestr[prel] != instr[root];root++);//找到中序遍历中的根
	leftsize = root - inl;
	rightsize = inr - root;
	if(leftsize > 0)//如果存在左子树
	{
		solve(prel + 1,prel + leftsize,inl,inl + leftsize - 1);
	}
	if(rightsize > 0)//如果存在右子树
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