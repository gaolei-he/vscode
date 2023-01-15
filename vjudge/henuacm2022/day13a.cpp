/*
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define inf 1e9
using namespace std;
const int N = 510;
double g[N][N];
int s, p;
double dist[N];
bool st[N];
double prim()
{
    int n = p;
    vector<double> tmp;
    for(int i=0;i<N;i++) dist[i] = inf;
    memset(st, 0, sizeof(st));
    double res = 0;
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for(int j=1;j<=n;j++)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        res += dist[t];
        tmp.push_back(dist[t]);
        for(int j=1;j<=n;j++) dist[j] = min(dist[j], g[t][j]);

        
        st[t] = true;

    }

    sort(tmp.begin(), tmp.end(), greater<double>());

    return tmp[s-1];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &s, &p);
        vector<pair<int, int> > pos;
        pos.push_back({0, 0});
        for (int i = 0; i < p; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            pos.push_back({x, y});
        }
        for(int i=1;i<p;i++)
        {
            for(int j=i+1;j<=p;j++)
            {
                int tmp = (pos[j].second - pos[i].second) * (pos[j].second - pos[i].second);
                tmp += (pos[j].first - pos[i].first) * (pos[j].first - pos[i].first);
                g[i][j] = g[j][i] = sqrt(tmp);
            }
        }

        double ans = prim();
        printf("%.2f\n", ans);
        
    }
    
    return 0;
}
*/
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 510;
struct Edge
{
    int a, b;
    double w;
    bool operator<(const Edge &W) const
    {
        return w < W.w;
    }
}edges[N*N];
int s, n; 
int p[N];
int find(int x)
{
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &s, &n);
        vector<pair<int, int> > tmp;
        tmp.push_back({0, 0});
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            tmp.push_back({x, y});
        }
        int cnt = 0;
        for(int i=1;i<tmp.size();i++)
        {
            for(int j=1;j<tmp.size();j++)
            {
                double dis = (tmp[i].first - tmp[j].first) * (tmp[i].first - tmp[j].first);
                dis += (tmp[i].second - tmp[j].second) * (tmp[i].second - tmp[j].second);
                dis = sqrt(dis);
                edges[cnt ++] = {i, j, dis};
            }
        }
        for(int i=1;i<=n;i++) p[i] = i;
        sort(edges, edges+cnt);
        double ans = 0;
        int tmp_cnt = 0;
        for (int i = 0; i < cnt; i++)
        {
            int a = edges[i].a, b = edges[i].b;
            double w = edges[i].w;
            int p1 = find(a), p2 = find(b);
            if(p1 == p2) continue;
            else 
            {
                p[p1] = p2;
                ans = w;
                tmp_cnt ++;
                if(tmp_cnt == n - s) break;

            }
        }
        printf("%.2f\n", ans);
        
    }
    
    return 0;
}