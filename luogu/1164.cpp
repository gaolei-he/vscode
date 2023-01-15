#include <iostream>
using namespace std;
const int N = 110, M = 10010;
typedef long long ll;
ll f[N][M];
ll ans;
int n, m, a[N];

ll dfs(int c, int k)
{
    if(f[c][k]) return f[c][k];
    if(a[c]>k) return 0;
    if(a[c]==k) return 1;
    for(int i=c+1;i<=n;i++)
        f[c][k] += dfs(i, k-a[c]);
    return f[c][k];
}

//记忆化递归
int main1()
{
    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    for(int i=1;i<=n;i++) ans += dfs(i, m);

    printf("%lld", ans);
    return 0;
}
//递推
int main()
{

    scanf("%d %d", &n, &m);

    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(j<a[i]) f[i][j] = f[i-1][j];
            else if(j==a[i]) f[i][j] = f[i-1][j] + 1;
            else f[i][j] = f[i-1][j] + f[i-1][j-a[i]];
        }

    printf("%lld", f[n][m]);
    return 0; 
}