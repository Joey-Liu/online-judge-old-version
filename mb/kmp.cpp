void getNext(char *p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	
	while(j < pLen - 1)
	{
		if(-1 == k || p[j] == p[k])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
			k = next[k];
	}//while j
}

int main()
{
	char *a = "ABCDABD";
	int next[7];
	getNext(a, next);
	return 0;
}