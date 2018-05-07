#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstddef>
#include <time.h>
#include <windows.h>
using namespace std;

//返回三个数的中位数
static char* med3(char* a, char* b, char* c, int(*cmp)(const void* ,const void* ))
{
	return cmp(a, b) < 0 ?
		(cmp(b, c) < 0 ? b : cmp(a, c) < 0 ? c : a)
		: (cmp(b, c)  > 0 ? b : cmp(a, c) > 0 ? c : a);
}

typedef long MWORD;
#define W sizeof(MWORD)
#define SWAPINIT(a,es) swaptype = (a - (char*)0 | es) % W ? 2 : es > W ? 1 : 0
#define exch(a,b,t) (t = a,a = b,b = t)
#define swap(a,b) swaptype != 0 ? swapfunc(a,b,es,swaptype) : (void)exch(*(MWORD*)(a),*(MWORD*)(b),t)
#define vecswap(a,b,n) if(n > 0) swapfunc(a,b,n,swaptype)
/////#define min(a,b) ((a) < (b)) ? (a) : (b)


static void swapfunc(char* a, char* b, size_t n, int swaptype)
{
	if (swaptype <= 1)
	{
		MWORD t;
		for (; n > 0; a += W, b += W, n -= W)
			exch(*(MWORD*)a, *(MWORD*)b, t);
	}
	else
	{
		char t;
		for (; n > 0; a += 1, b += 1, n -= 1)
			exch(*a, *b, t);
	}
}

#define PVINIT(pv,pm) if (swaptype != 0) pv = a, swap(pv, pm); else pv = (char *)&v,v = *(MWORD*)pm

void Eqsort(char* a, size_t n, size_t es, int(*cmp)(const void*, const void*))
{
	//pa为起始地址 排序过程中：0--pa- 1 等于枢轴 pa--pb - 1小于枢轴 pb--pc不确定 pc+ 1 --pd 大于枢轴
	//枢轴元素pv，pl,pm,pn 视具体情况而定,但均用于找出切分元素
	char *pa, *pb, *pc, *pd, *pl, *pm, *pn, *pv;
	int r, swaptype;
	MWORD t, v;
	size_t s;

	SWAPINIT(a, es);
	if (n < 7)//数量较少时使用插排
	{
		for (pm = a + es; pm < a + n * es; pm += es)
		for (pl = pm; pl > a && cmp(pl - es, pl) > 0; pl -= es)
			swap(pl, pl - es);
		return;
	}

	//使用三取样切分 或 Tukey ninther 方法得到中枢元素
	pm = a + (n / 2) * es;
	if (n > 7)
	{
		pl = a;
		pn = a + (n - 1) * es;
		if (n > 40)//对于较大数组使用ninther 方法
		{
			s = (n / 8) * es;
			pl = med3(pl, pl + s, pl + 2 * s, cmp);
			pm = med3(pm - s, pm, pm + s, cmp);
			pn = med3(pn - 2 * s, pn - s, pn, cmp);
		}//if n > 40
		pm = med3(pl, pm, pn, cmp);
	}
	PVINIT(pv, pm);
	pa = pb = a;
	pc = pd = a + (n - 1) *es;
	while (true)
	{
		while (pb <= pc && (r = cmp(pb, pv)) <= 0)
		{
			if (0 == r)
			{
				swap(pa, pb);
				pa += es;
			}
			pb += es;
		}
		while (pc >= pb && (r = cmp(pc, pv)) >= 0)
		{
			if (r == 0)
			{
				swap(pc, pd);
				pd -= es;
			}
			pc -= es;
		}
		if (pb > pc)
			break;
		swap(pb, pc);
		pb += es;
		pc -= es;
	}

	//下面的程序使得交换次数最少
	pn = a + n * es;
	s = min(pa - a, pb - pa);
	vecswap(a, pb - s, s);

	s = min(pd - pc, pn - pd - es);
	vecswap(pb, pn - s, s);
	if ((s = pb - pa) > es)
		Eqsort(a, s / es, es, cmp);
	if ((s = pd - pc) > es)
		Eqsort(pn - s, s / es, es, cmp);
}

int Integer_Cmp(const void* a, const void* b)
{
	int* _a = (int *)a;
	int* _b = (int *)b;
	return *_a - *_b;
}

const int maxn = 100000;

int main()
{
	freopen("out.txt", "w", stdout);
	clock_t start, finish;
	start = clock();
	srand(time(NULL));
	int num[maxn];
	for (int i = 0; i < maxn; i++)
		num[i] = rand() % 100;
	
	Eqsort((char*)num, maxn, sizeof(int), Integer_Cmp);
	//qsort(num, maxn, sizeof(int), Integer_Cmp);
	for (int i = 0; i < maxn; i++)
	{
		if (i % 50 == 0)
			printf("\n");
		printf("%d ", num[i]);
	}
	finish = clock();

	printf("%f seconds\n", (double)(finish - start) / CLOCKS_PER_SEC);
	return 0;
}
