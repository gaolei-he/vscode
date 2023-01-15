#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <functional>
#include <cstring>
#include <array>
using namespace std;
const int N = 100010;
struct Node
{
    int x, y, val;
    bool operator<(const Node& t) {
        return val < t.val;
    }
}node[N];

class Solution {
public:
    vector<int> p, sz;
    int n, m;
    int find(int x)
    {
        if(p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    vector<int> maxPoints(vector<vector<int>>& g, vector<int>& queries) {
        n = g.size(), m = g[0].size();
        p.resize(n*m), sz.resize(n*m);
        for(int i=0;i<n*m;i++) p[i] = i, sz[i] = 1;
        
        for(int x=0;x < n; x++)
            for(int y = 0; y < m; y++)
            node[x*m+y] = {x, y, g[x][y]};
        
        sort(node, node+n*m);
        vector<int> res(queries.size()), pos(queries.size());
        for(int i=0;i<pos.size();i++) pos[i] = i;
        sort(pos.begin(), pos.end(), [&](int a, int b){
            return queries[a] < queries[b];
        });
        int cnt = 0;
        int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};
        for(int k=0;k<pos.size();k++)
        {
            int query = queries[pos[k]];
            while(cnt < n * m && node[cnt].val < query)
            {
                int x = node[cnt].x, y = node[cnt].y, val = node[cnt].val;
                cnt ++;
                for (int i = 0; i < 4; i++)
                {
                    int a = x + dx[i], b = y + dy[i];
                    int id1 = x * m + y, id2 = a * m + b;
                    if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] < query)
                    {
                        int u = find(id1), v = find(id2);
                        if(u != v)
                        {
                            p[u] = v;
                            sz[v] += sz[u];
                        }
                    }
                }
                
            }
            if(g[0][0] < query)
                res[pos[k]] = sz[find(0)];

        }
        return res;

    }
};


int main()
{

    return 0;
}