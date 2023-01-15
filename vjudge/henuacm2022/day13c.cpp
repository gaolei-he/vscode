#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 110;
int g[N][N], dist[N];
int n;
bool st[N];


int prim()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    int res = 0;
    memset(st, 0, sizeof(st));
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j=1;j<=n;j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        st[t] = true;
        res += dist[t];
        for(int j=1;j<=n;j++) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
    
}

int main()
{
    while (cin >> n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d", &g[i][j]);
        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            g[a][b] = g[b][a] = 0;
        }
        
        int t = prim();
        cout << t << endl;
    }
    
    return 0;
}