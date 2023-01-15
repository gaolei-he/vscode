#include <iostream>
#include <cstdio>
#include <cstring>
#define inf 0x3f3f3f3f
using namespace std;
const int N = 110;
int g[N][N], dist[N];
int n, m;
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    int res = 0;
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j=1;j<=n;j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        if(dist[t] == inf) return inf;
        res += dist[t];
        for(int j=1;j<=n;j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
    
}

int main()
{
    while (cin >> n)
    {
        if(!n) break;
        memset(g, 0x3f, sizeof(g));
        m = n * (n - 1) / 2;
        while(m--)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            g[a][b] = g[b][a] = min(c, g[a][b]);
        }

        int t = prim();
        if(t == inf) puts("?");
        else cout << t << endl;
    }
    
    return 0;
}