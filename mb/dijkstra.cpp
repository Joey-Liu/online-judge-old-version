    #include <cstdio>  
    #include <iostream>  
    #include <algorithm>  
    #define MAX 100  
    #define INF 1000000000  
    using namespace std;  
    int dijkstra (int mat[][MAX],int n, int s,int f)  
    {//s为起点， f：为终点  
        int dis[MAX];//记录到任意点的最短距离  
        int mark[MAX];//记录被选中的结点   
        int i,j,k = 0;  
        for(i = 0 ; i < n ; i++)//初始化所有结点，每个结点都没有被选中   
            mark[i] = 0;  
        for(i = 0 ; i < n ; i++)//将每个结点到start结点weight记录为当前distance   
        {  
            dis[i] = mat[s][i];  
            //path[i] = s;  
        }  
        mark[s] = 1;//start结点被选中   
        //path[s] = 0;  
        dis[s] = 0;//将start结点的的距离设置为0   
        int min ;//设置最短的距离。   
        for(i = 1 ; i < n; i++)  
        {  
            min = INF;  
            for(j = 0 ; j < n;j++)  
            {  
                if(mark[j] == 0  && dis[j] < min)//未被选中的结点中，距离最短的被选中   
                {  
                    min = dis[j] ;  
                    k = j;  
                }  
            }  
            mark[k] = 1;//标记为被选中   
            for(j = 0 ; j < n ; j++)  
            {  
                if( mark[j] == 0  && (dis[j] > (dis[k] + mat[k][j])))//修改剩余结点的最短距离   
                {  
                    dis[j] = dis[k] + mat[k][j];  
                }  
            }  
        }  
        return dis[f];      
    }   
    int mat[MAX][MAX];  
    int main()  
    {  
        int n,m;  
        while(scanf("%d %d",&n,&m))  
        {  
            int a,b,dis;  
            if(n == 0 || m == 0)  
                break;  
            int i,j;  
            for(i = 0 ; i < n;i++)  
                for(j = 0 ; j < n; j++)  
                    mat[i][j] = INF;  
			for(i = 0 ; i < m ;i++)  
			{  
				scanf("%d %d %d",&a,&b,&dis);  
				--a,--b;  
				if(dis < mat[a][b] || dis < mat[b][a])  
					mat[a][b] = mat[b][a] = dis;  
			}  
                int ans = dijkstra(mat,n,0,n-1);  
                printf("%d\n",ans);  
        }  
        return 0;  
    }  