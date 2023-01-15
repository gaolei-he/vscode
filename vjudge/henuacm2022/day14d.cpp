#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
const int N = 2e4+10;
int son[N][26], idx;
int cnt[N];
char str[30];
void insert()
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++;
    }
}
void query()
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int u = str[i] - 'a';
        if(cnt[p] == 1)
        {
            str[i] = 0;
            return;
        }
        else p = son[p][u];
    }
}
int main()
{
    vector<string> tmp;
    while(scanf("%s", str) != EOF)
    {
        tmp.push_back(str);
        insert();
    }
    for(int i=0;i<tmp.size();i++)
    {
        memcpy(str, tmp[i].c_str(), tmp[i].size()+1);
        cout << tmp[i] << ' ';
        query();
        printf("%s\n", str);
    }
    return 0;
}