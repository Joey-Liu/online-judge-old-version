#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
char map[9][9];//������Թ�����
int dir[4][2] = { { 1, 0 },{ 0, 1 },{ -1, 0 },{ 0, -1 } };//4������
int OK = 0;
int N, M, T, si, sj, di, dj;
int dfs(int si, int sj, int cnt)
{
	if (si <= 0 || sj <= 0 || si > N || sj > M)//�����߽��˵������·�Ѿ����ˣ��򷵻�
	{
		return 0;
	}
	if (si == di && sj == dj && cnt == T)//�ҵ��յ�ͷ��أ��ѱ�־λ��Ϊ1
	{
		OK = 1;
	}
	if (OK)
	{
		return 1;
	}
	int temp = T - cnt - abs(di - si) - abs(dj - sj);//������Ǽ�֦����ʼûд���Time Limit Exceeded��ʮ����...����ϸ̸
	if (temp < 0 || temp & 1)
	{
		return 0;
	}
	for (int i = 0; i < 4; ++i)//���ߵ���ÿ����㶼�����ĸ������̽��
	{
		if (map[si + dir[i][0]][sj + dir[i][1]] != 'X')
		{
			map[si + dir[i][0]][sj + dir[i][1]] = 'X';//�߹���·�����ߣ�������Ϊǽ
			dfs(si + dir[i][0], sj + dir[i][1], cnt + 1);
			//map[si + dir[i][0]][sj + dir[i][1]] = '.';//̽����һ��·ʱ��������Ҫ�ָ��ɿ����ߵ�״̬
		}
	}
	return 0;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	while (cin >> N >> M >> T)
	{
		int wall = 0;
		OK = 0;
		if (N == 0 && M == 0 && T == 0)
		{
			break;
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= M; ++j)
			{
				cin >> map[i][j];//���￪ʼ��д��scanf("%c", &map[i][j]);���Ĳ�̸��...  ��������������for(i)��ѭ������д scanf("%s", &map[i]);
				if (map[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				else if (map[i][j] == 'D')
				{
					di = i;
					dj = j;
				}
				else if (map[i][j] == 'X')
				{
					wall++;
				}
			}
		}
		if (N * M - wall <= T)//һ��С��֦
		{
			cout << "NO" << endl;
			continue;
		}
		map[si][sj] = 'X';
		dfs(si, sj, 0);
		if (OK)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}