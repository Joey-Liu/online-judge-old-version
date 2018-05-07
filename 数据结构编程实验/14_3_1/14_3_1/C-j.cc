/* Copyright John Bonomo (ACM ICPC ECNA 1999) */

#include <iostream>
#include <string>
using namespace std;

int numReceps, numPlugs, numAdapts, globalMax;

string names[400];              // yes, this was originally 300
int nnames;

bool receps[100];

//设备信息
struct plug {
   int val;
   bool list[400];              // this too
} plugs[100];

struct adapt {
        int recep, plug;
} adapts[100];

int matchPlug[100], matchRecep[100];
bool canUse[100];

int findName(string name)
{
        for(int i=0; i<nnames; i++)
        if (name == names[i])
        return i;
   names[nnames++] = name;
   return nnames-1;
}

void setList(int i)
{
        plugs[i].list[plugs[i].val] = true;
   bool flag;
   do {
        flag = false;
      for(int j=0; j<numAdapts; j++) {
        if (plugs[i].list[adapts[j].recep] && !plugs[i].list[adapts[j].plug]) {
                flag = true;
            plugs[i].list[adapts[j].plug] = true;
         }
      }
   } while (flag);
}

bool findAugPath(int node)
{
        for(int j=0; j<numReceps; j++) {
        if (plugs[node].list[j] && canUse[j]) {
        if (matchRecep[j] == -1) {
                matchPlug[node] = j;
            matchRecep[j] = node;
            return true;
         }
         else {
                int save = matchRecep[j];
            matchRecep[j] = node;
            matchPlug[save] = -1;
            matchPlug[node] = j;
            canUse[j] = false;
            if (findAugPath(save))
                return true;
            canUse[j] = true;
            matchPlug[node] = -1;
            matchPlug[save] = j;
            matchRecep[j] = save;
         }
      }
   }
   return false;
}

void main()
{
        string name;
   //初始化插座数量 名称
   cin >> numReceps;
   for(int i=0; i<numReceps; i++) {
        cin >> names[i];
      receps[i] = false;
   }
   nnames = numReceps;

   //设备数量 名称
   cin >> numPlugs;
   for(int i=0; i<numPlugs; i++) {
      cin >> name >> name;
      plugs[i].val=findName(name);//设备编号
      for(int j=0; j<100; j++)
                plugs[i].list[j] = false;
   }
   //转换器信息
   cin >> numAdapts;
   for(int i=0; i<numAdapts; i++) {
        cin >> name;
      adapts[i].recep = findName(name);//转换后的插座
      cin >> name;
      adapts[i].plug = findName(name);//需要的插座
   }

   for(int i=0; i<numPlugs; i++)
        setList(i);
        for(int i=0; i<100; i++) {
        matchPlug[i] = matchRecep[i] = -1;
   }

   int i=0;
   while(i < numPlugs) {
        for(int j=0; j<numReceps; j++)
        canUse[j] = true;
        if (matchPlug[i] == -1 && findAugPath(i)) {
        i = 0;
      }
      else
        i++;
   }

   int min = 0;
   for(int i=0; i<numPlugs; i++)
        if (matchPlug[i] == -1) min++;
   cout << min << endl;
}
