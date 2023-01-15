#include <iostream>
using namespace std;
const int N = 1e5+10;
int son[N][2], cnt[N];
int idx, a[N];
char s[33];
void insert(char str[])
{
    int p = 0;
    for (int i = 0; str[i] ; i++)
    {
        int u = str[i] - '0';
        if(!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] = true;
    
}
inline void get(int x)
{
    for(int i=0;i<32;i++)
    {
        if((1<<31-i)&x) s[i] = '1';
        else s[i] = '0';
    }
}
inline int f()
{
    int p = 0;
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        int u = s[i] - '0';
        u = u ? 0 : 1;
        if(!son[p][u]) p = son[p][u?0:1];
        else
        {
            p = son[p][u];
            ans |= (1<<31-i);
        }
    }
    return ans;
    
}

int main()
{
    int n, ans = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        get(a[i]);
        insert(s);
    }
    for (int i = 0; i < n; i++)
    {
        get(a[i]);
        ans = max(ans, f());
    }
    cout << ans;
    return 0;
}