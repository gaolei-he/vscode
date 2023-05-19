#include <iostream>
#include <cmath>
#define lowbit(x) ((x) & (-x))
using namespace std;
const int N = 1e5+10;
int f[N][25], g[N][25];
int lg[N];
int n, q;
int main()
{
    lg[1] = 0, lg[2] = 1;
    for(int i=3;i<N;i++) if(lowbit(i) == i) lg[i] = lg[i-1] + 1; else lg[i] = lg[i-1];
    cin >> n >> q;//n个数，q次询问
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d", &x);
        f[i][0] = g[i][0] = x;
    }
    int ed = 25;
    for(int j=1;j<=ed;j++)
        for(int i=1;i+(1<<j)-1 <= n;i++)
        {
            f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);

            g[i][j] = min(g[i][j-1], g[i+(1<<(j-1))][j-1]);
        }
        
    while (q--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        int s = lg[b-a+1];
        //最大值与最小值的差
        printf("%d\n", max(f[a][s], f[b-(1<<s)+1][s]) - min(g[a][s], g[b-(1<<s)+1][s]));
    }
    
    return 0;
}