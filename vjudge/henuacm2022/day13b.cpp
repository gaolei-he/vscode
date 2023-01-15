#define inf 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 510;
int n, m;
int g[N][N];
int dist[N];
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
        if(dist[t] == inf) return inf;
        res += dist[t];
        for(int j=1;j<=n;j++) dist[j] = min(dist[j], g[t][j]);

        
        st[t] = true;

    }
    return res;
}

int main()
{
    while(cin >> n)
    {

        memset(g, 0x3f, sizeof(g));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d", &g[i][j]);

        int t = prim();
        if(t == inf) puts("impossible");
        else cout << t << endl;
    }
    
    return 0;
}