#include <vector>
#include <set>
#include <functional>
#include <iostream>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
private:
    vector<int> p;
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        vector<int> deg(edges.size(), 0);
        vector<int> res(edges.size(), 0);
        vector<int> sz(edges.size(), 1);
        for(auto x : edges) deg[x] ++;
        p.resize(edges.size());
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x)
        {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for(int i=0;i<edges.size();i++)
        {
            int u = find(i), v = find(edges[i]);
            if(u == v) continue;
            p[u] = v;
            sz[v] += sz[u];
        }

        map<int, set<int>> mp;
        vector<int> points;
        vector<bool> vis(edges.size(), false);
        bool fg = false;
        function<void(int)> dfs1 = [&](int u)
        {
            if(vis[u])
            {
                if(mp.count(find(u))) return;
                fg = false;
                int val = find(u);
                for(auto x : points)
                {
                    if(x == u) fg = true;
                    if(fg) mp[val].insert(x);
                }
                points.clear();
                return;
            }
            points.push_back(u);
            vis[u] = true;
            dfs1(edges[u]);
        };
        for(int i=0;i<edges.size();i++)
            if(deg[i] == 0)
                dfs1(i);
        function<void(int)> dfs2 = [&](int u)
        {
            if(mp[find(u)].count(u) or res[u])
            {
                int val = 0;
                if(res[u]) val = res[u];
                else val = mp[find(u)].size();
                int tmp = points.size();
                for(auto x : points)
                {
                    res[x] = val + tmp;
                    tmp --;
                }
                points.clear();
                return;
            }
            points.push_back(u);
            dfs2(edges[u]);
        };
        for(int i=0;i<edges.size();i++)
            if(deg[i] == 0)
                points.clear(), dfs2(i);
        for(auto &[k, vec] : mp)
            for(auto x : vec)
                res[x] = vec.size();
        for(int i=0;i<res.size();i++)
            if(!res[i])
                res[i] = sz[find(i)];
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> edges = {7,0,7,0,5,3,3,0};
    auto res = s.countVisitedNodes(edges);
    for(auto x : res) cout << x << ' ';
    cout << endl;
    return 0;
}