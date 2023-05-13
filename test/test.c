#include <stdio.h>
#define N 200
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define rep(i, a, n) for(int i=(a);i<=(n);++i)
double w[N][N], m[N][N];
double a[N], b[N], sa[N], sb[N];
void dfs(int l, int r)
{
    if(l == r)
    {
        printf("%d ", l);
        return;
    }
    else if(l > r) return;
    int mi = 1e9;
    int root = -1;
    rep(i, l+1, r)
    {
        if(m[l][i-1] + m[i+1][r] + m[i][i] < mi)
            mi = m[l][i-1] + m[i+1][r] + m[i][i], root = i;
    }
    printf("%d ", root);
    dfs(l, root-1);
    dfs(root+1, r);
}
int main()
{
    int n;
    scanf("%d%lf", &n, &a[0]);
    rep(i, 1, n) scanf("%lf %lf", &b[i], &a[i]);
    sa[0] = a[0];
    rep(i, 1, n) sa[i] = sa[i-1] + a[i], sb[i] = sb[i-1] + b[i];
    rep(i, 1, n)
        rep(j, i, n)
            if(j != 1) w[i][j] = sb[j] - sb[i-1] + sa[j] - sa[i-2];
            else w[i][j] = sb[j] - sb[i-1] + sa[j];
    
    rep(i, 0, n)
        rep(j, 0, n)
            if(i - 1 == j)
                m[i][j] = 0;
            else
                m[i][j] = 1e9;
    rep(l, 0, n)
        rep(i, 1, n)
        {
            int j = i + l;
            if(j > n) break;
            rep(k, i, j)
                m[i][j] = min(m[i][j], m[i][k-1] + m[k+1][j] + w[i][j]);
        }
    dfs(1, n);
}