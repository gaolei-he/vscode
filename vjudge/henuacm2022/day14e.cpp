#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
char str[15];
const int N = 1e5+10;
int son[N][10], idx;
bool ans = true;
int cnt[N];
bool cnt1[N];
void insert()
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int u = str[i] - '0';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
        cnt[p] ++;
        if(cnt1[p]) ans = false;
        
    }
    cnt1[p] = true;
    if(cnt[p] > 1) ans = false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        idx = 0;
        ans = true;
        memset(son, 0, sizeof(son));
        memset(cnt, 0, sizeof(cnt));
        memset(cnt1, 0, sizeof(cnt1));
        scanf("%d", &n);
        while(n--)
        {
            scanf("%s", str);
            insert();
        }
        if(!ans) puts("NO");
        else puts("YES");
    }
    
    return 0;
}