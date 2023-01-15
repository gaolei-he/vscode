#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5+10;
int n, m, s, t;
int e[N], ne[N], idx, w[N], l[N], h[N];
int cost[N], dist[N];
bool st[N];
void add(int a, int b, int d, int p)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = d, l[idx] = p;
    h[a] = idx ++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII> > q;
    dist[s] = 0;
    cost[s] = 0;
    q.push({0, s});
    while (q.size())
    {
        PII t = q.top();
        q.pop();
        int ver = t.second, distan = t.first;
        if(st[ver]) continue;
        for(int i=h[ver];~i;i=ne[i])
        {
            int j = e[i];
            //if(st[j]) continue;
            if(dist[j] > distan + w[i])
            {
                dist[j] = distan + w[i];
                cost[j] = cost[ver] + l[i];
                q.push({dist[j], j});
            }
            else if(dist[j] == distan + w[i])
            {
                cost[j] = min(cost[j], cost[ver] + l[i]);
            }
        }
        st[ver] = true;
    }
    cout << dist[t] << ' ';
    cout << cost[t] << endl;
    
}

int main()
{
    while(1)
    {
        memset(h, -1, sizeof(h));
        memset(cost, 0x3f, sizeof(cost));
        memset(dist, 0x3f, sizeof(dist));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        memset(l, 0, sizeof(l));
        memset(w, 0, sizeof(w));
        memset(st, 0, sizeof(st));
        idx = 0;
        cin >> n >> m;
        if(!n) break;
        while (m--)
        {
            int a, b, d, p;
            scanf("%d %d %d %d", &a, &b, &d, &p);
            add(a, b, d, p);
            add(b, a, d, p);
        }
        cin >> s >> t;
        dijkstra();
    }

    return 0;
}