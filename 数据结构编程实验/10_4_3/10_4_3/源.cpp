    #include <iostream>  
    #include <queue>  
	#include <functional>
    using namespace std;  
      
    #define M 30005  
    int array[M];  
      
    priority_queue< int,vector<int>,less<int> > maxHeap;  
    priority_queue< int,vector<int>,greater<int> > minHeap;  
      
    int main()  
    {  
        freopen("501.in","r",stdin);
		freopen("out.txt","w",stdout);
		int n, m, i;  
        scanf("%d%d",&n,&m);  
        for ( i = 0; i < n; ++i )  
            scanf("%d",array+i );  
      
        int oper = 0, k = 0, t1, t2;  
        for ( i = 0; i < m; ++i )  
        {  
            scanf("%d",&oper);  
            while ( k < oper )  
            {  
                minHeap.push ( array[k] );  
                if ( ! maxHeap.empty() && minHeap.top() < maxHeap.top() )  
                {  
                    t1 = minHeap.top(); minHeap.pop();  
                    t2 = maxHeap.top(); maxHeap.pop();  
                    maxHeap.push(t1); minHeap.push(t2);  
                }  
                ++k;  
            }  
            printf("%d\n",minHeap.top());  
            maxHeap.push ( minHeap.top() );  
            minHeap.pop();  
        }  
        return 0;
    }  