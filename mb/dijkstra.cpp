    #include <cstdio>  
    #include <iostream>  
    #include <algorithm>  
    #define MAX 100  
    #define INF 1000000000  
    using namespace std;  
    int dijkstra (int mat[][MAX],int n, int s,int f)  
    {//sΪ��㣬 f��Ϊ�յ�  
        int dis[MAX];//��¼����������̾���  
        int mark[MAX];//��¼��ѡ�еĽ��   
        int i,j,k = 0;  
        for(i = 0 ; i < n ; i++)//��ʼ�����н�㣬ÿ����㶼û�б�ѡ��   
            mark[i] = 0;  
        for(i = 0 ; i < n ; i++)//��ÿ����㵽start���weight��¼Ϊ��ǰdistance   
        {  
            dis[i] = mat[s][i];  
            //path[i] = s;  
        }  
        mark[s] = 1;//start��㱻ѡ��   
        //path[s] = 0;  
        dis[s] = 0;//��start���ĵľ�������Ϊ0   
        int min ;//������̵ľ��롣   
        for(i = 1 ; i < n; i++)  
        {  
            min = INF;  
            for(j = 0 ; j < n;j++)  
            {  
                if(mark[j] == 0  && dis[j] < min)//δ��ѡ�еĽ���У�������̵ı�ѡ��   
                {  
                    min = dis[j] ;  
                    k = j;  
                }  
            }  
            mark[k] = 1;//���Ϊ��ѡ��   
            for(j = 0 ; j < n ; j++)  
            {  
                if( mark[j] == 0  && (dis[j] > (dis[k] + mat[k][j])))//�޸�ʣ�������̾���   
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