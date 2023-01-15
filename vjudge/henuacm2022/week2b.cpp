#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e4+10, M = 1e5+10;
bool st[N];
int n, m, t, x, idx;
int e[M], ne[M], h[M], times[M], loads[M];
int dist[N];
typedef pair<int, int> PII;
void add(int a, int b, int c, int d)
{
    e[idx] = b, ne[idx] = h[a], times[idx] = d, loads[idx] = c;
    h[a] = idx ++;
}

bool check(int mid)
{
    memset(dist, 0x3f, sizeof(dist));
    memset(st, 0, sizeof(st));
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII> > q;
    q.push({0, 1});
    while (q.size())
    {
        PII t = q.top();
        q.pop();
        int ver = t.second, dis = t.first;
        if(st[ver]) continue;
        //if(dis < mid) continue;
        for(int i=h[ver];~i;i=ne[i])
        {
            int j = e[i];
            if(loads[i] < mid) continue;
            if(dist[j] > dis + times[i])
            {
                dist[j] = dis + times[i];
                q.push({dist[j], j});
            }
        }
        st[ver] = true;
    }
    return dist[n] <= t;

}
int main()
{
    cin >> x;
    while (x--)
    {
        memset(h, -1, sizeof(h));
        memset(e, 0, sizeof(e));
        memset(ne, 0, sizeof(ne));
        memset(times, 0, sizeof(times));
        memset(loads, 0, sizeof(loads));
        idx = 0;
        scanf("%d %d %d", &n, &m, &t);
        int r = 0, l = 2e9+10;
        while (m--)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            add(a, b, c, d);
            add(b, a, c, d);
            l = min(l, c);
            r = max(r, c);
        }
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
        
    }
    
    return 0;
} 