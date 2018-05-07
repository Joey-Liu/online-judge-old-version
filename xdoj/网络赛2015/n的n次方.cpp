    #include <iostream>  
    #include <stdlib.h> 
    #include <limits>  
    #include <cmath>  
    using namespace std;  
      
    int GetHighest(const double& n)  
    {  
    //求n^n的最高位  
    //注意：n取 1，2，3，...，1000000000  
      
        double intpart;  
        double fractpart = modf ( n * log10(n), &intpart);  
      
        //显然分数部分在[0,1)之间，所以temp在[1,10)之间，那么整数部分即为结果  
        double temp = pow( (double)10, fractpart);  
      
        modf ( temp, &intpart);  
      
        return intpart;  
    }  
      
    int main()   
    {   
        //cout<<numeric_limits<double>::max()<<endl;  
              
        cout<<GetHighest(1)<<endl;  
        cout<<GetHighest(2)<<endl;  
        cout<<GetHighest(3)<<endl;  
        cout<<GetHighest(4)<<endl;  
        cout<<GetHighest(5)<<endl;  
        cout<<GetHighest(6)<<endl;  
        cout<<GetHighest(4678)<<endl;  
        cout<<GetHighest(1000)<<endl;  
        cout<<GetHighest(1000000000)<<endl;  
        cout<<GetHighest(1999)<<endl;  
        cout<<GetHighest(999999999)<<endl;
        system("pause");  
        return 0;
    }  
