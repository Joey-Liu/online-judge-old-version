#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <memory.h>

using namespace std;

const int maxn = 20;
char cube_str[maxn], cube_1[maxn] = { 0 }, cube_2[maxn] = {0};
bool flag = false;

void rotate_vet()
{
	char tmp[maxn] = { 0 };
	char cu[maxn];
	
	for(int k = 0; k < 2; k++)
	{
		if(!k)
		{
			strcpy(cu, cube_2);
			strcpy(tmp, cu);
		}
		else
		{
			strcpy(cu, cube_2);
			cu[0] = cube_2[5];
			cu[5] = cube_2[0];
			cu[2] = cube_2[3];
			cu[3] = cube_2[2];
			strcpy(tmp, cu);
		}
		for (int i = 0; i < 4; i++)
		{
			tmp[2] = cu[1];
			tmp[4] = cu[2];
			tmp[3] = cu[4];
			tmp[1] = cu[3];
			if (!strcmp(tmp, cube_1))
			{
				flag = true;
				break;
			}
			strcpy(cu, tmp);
		}
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	while (EOF != scanf("%s", cube_str))
	{
		flag = false;
		strcpy(cube_2, cube_str + 6);
		for (int i = 0; i < 6; i++)
			cube_1[i] = cube_str[i];
		
		char cube_tmp[maxn] = { 0 };
		strcpy(cube_tmp, cube_2);
		for (int i = 0; i < 3; i++)
		{
			if (0 == i)
				rotate_vet();
			else if (1 == i)
			{
				strcpy(cube_2, cube_tmp);
				cube_2[0] = cube_tmp[1];
				cube_2[4] = cube_tmp[0];
				cube_2[5] = cube_tmp[4];
				cube_2[1] = cube_tmp[5];
				rotate_vet();
			}
			else
			{
				strcpy(cube_2, cube_tmp);
				cube_2[0] = cube_tmp[2];
				cube_2[3] = cube_tmp[0];
				cube_2[5] = cube_tmp[3];
				cube_2[2] = cube_tmp[5];
				rotate_vet();
			}
		}
		if (flag)
			printf("TRUE\n");
		else
			printf("FALSE\n");
	}//while
	return 0;
}