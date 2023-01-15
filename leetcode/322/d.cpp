#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> d;
    vector<vector<int>> g;
    vector<int> p;
    vector<int> dist;
    int n;

    const int inf = 1e9+10;
    int find(int x) {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void spfa(int start) {
        bool st[1+n];
        memset(st, 0, sizeof(st));
        dist.resize(n + 1);
        for(int i=1;i<=n;i++) dist[i] = inf;
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        st[start] = true;
        while(q.size())
        {
            int t = q.front();
            q.pop();
            for(auto j:g[t]) {
                if(dist[j] > dist[t]+1) {dist[j] = dist[t] + 1; if(!st[j])q.push(j);}
            }
        }
        for(int i=1;i<=n;i++) d[start][i] = dist[i];
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        this->n = n;
        p.resize(n + 1);
        
        g.resize(n + 1);
        d = vector<vector<int>>(n+1, vector<int>(n+1, inf));
        for(int i=1;i<=n;i++) p[i] = i, d[i][i] = 0;
        
        for(auto&edge:edges)
        {
            int a = edge[0], b = edge[1];
            g[a].push_back(b);
            g[b].push_back(a);
            p[find(a)] = find(b);
        }
        for(int i=1;i<=n;i++) spfa(i);
        vector<vector<int>> vers(n+1);
        for(int i=1;i<=n;i++) vers[find(i)].push_back(i);
        int res = 0;
        for(auto& ver:vers)
        {
            if(ver.empty()) continue;
            int mx = 0;
            for(int start:ver) {
                for(auto& edge:edges) if(d[start][edge[0]] < inf && d[start][edge[0]] == d[start][edge[1]]) return -1;
                for(auto end:ver) mx = max(mx, d[start][end]);
            }
            res += mx + 1;
        }
        return res;
    }
};
int main()
{

    return 0;
}