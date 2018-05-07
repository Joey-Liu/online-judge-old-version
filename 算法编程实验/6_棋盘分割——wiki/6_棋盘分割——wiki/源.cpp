#include <iostream>
#include <cmath>
using namespace std;

#define MIN(a, b) a>b?b:a

const int size = 9;
const int nMax = 15;
const int inf = 10000000; //���и�С�ɻ󣬲��ܽ�inf��ʼ��Ϊ0x7fffffff��INT_MAX

int dp[nMax][size][size][size][size];
int sum[size][size]; //��¼�������Ͻ�Ϊ��1��1�������о��εĺ�

int getSum(int x1, int y1, int x2, int y2) //��������sum�洢��ֵ��������εĺ�
{
	return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

int cut(int k, int x1, int y1, int x2, int y2)
{
	int s1, s2;
	
	if(dp[k][x1][y1][x2][y2] != -1) //�Ѿ�����Ϳ���ֱ�ӷ����ˣ������ظ�����
		return dp[k][x1][y1][x2][y2];
    if(k == 1)   // k == 1˵���и���n-1�Σ����ʣ�µ�һ����������͵�ƽ��ֱ�ӷ���
	{
		s1 = getSum(x1, y1, x2, y2);
        return (dp[k][x1][y1][x2][y2] = s1*s1);
	}
    //ˮƽ������
	int min = inf, tmp1; // min��¼����������и��ֵ��С��                    
	for(int x = x1; x < x2; x++)
	{
		s1 = getSum(x1, y1, x, y2);
		s2 = getSum(x+1, y1, x2, y2);
		tmp1 = MIN(cut(k-1, x+1, y1, x2, y2) + s1*s1, cut(k-1, x1, y1, x, y2) + s2*s2); 
		                           //���򽫵�ǰ�ľ����и�Ϊ����󣬼�������������и��󷵻�ʱ��ѡȡ�õ���ֵ��С��
		if(tmp1 < min)
			min = tmp1;                          
	}
	//��ֱ������
	int tmp2;
	for(int y = y1; y < y2; y++)
	{
        s1 = getSum(x1, y1, x2, y);
		s2 = getSum(x1, y+1, x2, y2);
		tmp2 = MIN(cut(k-1, x1, y+1, x2, y2) + s1*s1, cut(k-1, x1, y1, x2, y) + s2*s2);//������и�����
		if(tmp2 < min)
			min = tmp2;
	}
	return (dp[k][x1][y1][x2][y2] = min);
}


int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i, j, val, total, n;
    double avrg;
	
	while(scanf("%d", &n) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum)); //�����sum��ʼ��Ϊ0
		total = 0;
		
		for(i = 1; i < size; i++)//ע��i��j��1��ʼ
			for(j = 1; j < size; j++)
			{
				scanf("%d", &val);
				total += val;
				sum[i][j] = val + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1]; //ע��i��jΪ1ʱ�Ĵ����洢sum[i][j]
			}
		avrg = total*1.0/n;
		
		int res = cut(n, 1, 1, size-1, size-1);
		double ans = sqrt(res*1.0 / n - avrg*avrg); 
		//printf("%d",dec)
		printf("%.3lf\n", ans);
		//system("pause");
	}
	return 0;
}