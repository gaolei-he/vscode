#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
char str[20];
const int N = 1e7+10;
int son[N][26], idx;
int cnt[N];
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

int query()
{
    int p = 0;
    for(int i=0;str[i];i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

int main()
{
    while(scanf("%s", str) != EOF)
    {
        insert();
        vector<int> a;
        while(cin.peek() < 'a') a.push_back(getchar());
        sort(a.begin(), a.end());
        if(a.size() > 1 && a[0] == a[1] && a[0] == 10) break;

    }
    while(scanf("%s", str) != EOF)
    {
        int t = query();
        printf("%d\n", t);
    }
    return 0;
}