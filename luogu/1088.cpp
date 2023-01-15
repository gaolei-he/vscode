#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#if 0
int main()
{
    int n, m, cnt = 0;
    cin >> n >> m;
    int a[n];
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    while(next_permutation(a, a+n))
    {
        cnt ++;
        if(cnt==m)
        {
            printf("%d", a[0]);
            for(int i=1;i<n;i++) printf(" %d", a[i]);
            break;
        }
    }

    return 0;
}
#endif
#define N 10009
int a[N], b[N], c[N];
int n, m, cnt = 0, ret = 0;
void dfs(int k)
{
    if(ret) return;
    if(k==n)
    {
        cnt ++;
        ret = (cnt-1==m?1:0);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!cnt) i = a[k+1];
        if(!b[i])
        {
            b[i] = 1;
            c[k+1] = i;
            dfs(k+1);
            if(ret) return;
            b[i] = 0;
        }
    }
}

int main()
{
    
    cin >> n >> m;

    memset(b, 0, sizeof(b));

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);
    dfs(0);
    for(int i=1;i<=n;i++) printf("%d ", c[i]);
    return 0;
}