#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define N 105

vector<int> map[N];
int n, uset[N], ancestor[N], u, v, flag[N], deg[N], root;

//并查集的操作。
int find( int x )
{
 if(uset[x]==x)
	return x;
 else 
	return uset[x]=find(uset[x]);

}

void Union( int x, int y )
{
    int a= find(x), b= find(y);
    uset[a]= b; }
    
void LCA( int x )
{
    uset[x]= x; ancestor[x]= x;
    for( size_t i= 0; i< map[x].size(); ++i ){
        int y= map[x][i];
        LCA( y );
        
        Union( x, y );
        ancestor[ find(y) ]= x;
    }
    flag[x]= 1;
    if( x== u && flag[v] ){
        printf("%d\n", ancestor[ find(v) ] );
        return; }
    else if( x== v && flag[u] ){
        printf("%d\n", ancestor[ find(u) ] );
        return; }
}

int main()
{
    freopen("in.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test;
    scanf("%d",&test );
    while( test-- )
	{
        scanf("%d",&n);
        
        for( int i= 0; i<= n; ++i ) { ancestor[i]= 0; flag[i]= 0; deg[i]= 0; }
        for( int i= 1; i< n; ++i )
		{
            int x, y;
            scanf("%d%d", &x, &y);
            map[x].push_back(y);
            deg[y]++;
        }
        //scanf("%d%d",&u,&v);
        //for( int i= 1; i<= n; ++i )
		//	if( deg[i]== 0 ) 
		//		root= i;
        int m;
		scanf("%d",&m);
		while (m--)
		{
			scanf("%d %d %d",&root,&u,&v);
			deg[root] = 0;
			for( int i= 0; i<= n; ++i ) { ancestor[i]= 0; flag[i]= 0;}
			LCA( root );
		}
		for( int i= 0; i<= n; ++i ) map[i].clear();
    }
    
    return 0;
}