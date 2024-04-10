#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    std::vector<std::array<int, 3>> edges;
    while (m--) {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
        edges.push_back({u, v, w});
    }
    std::sort(edges.begin(), edges.end(),
              [&](auto a, auto b) { return a[2] > b[2]; });
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::function<int(int)> find = [&](int x) {
        return (x == p[x]) ? x : (p[x] = find(p[x]));
    };
    int mi = -1, st = -1, ed = -1;
    for (auto [u, v, w] : edges) {
        int a = find(u), b = find(v);
        if (a != b) {
            p[a] = b;
        } else {
            st = u, ed = v;
            mi = w;
        }
    }
    std::vector<int> ans;
    std::vector<bool> vis(n, false);
    std::function<void(int)> dfs = [&](int ver) {
        vis[ver] = true;
        ans.emplace_back(ver);
        if(ans.back() == ed) {
            return;
        }
        for(auto x : g[ver]) {
            if(ver == st and x == ed) {
                continue;
            }
            if(!vis[x]) {
                dfs(x);
                if(ans.size() and ans.back() == ed) {
                    return;
                }
                ans.pop_back();
            }
        }
    };
    dfs(st);
    std::cout << mi << " " << ans.size() << "\n";
    for (auto x : ans) {
        std::cout << x + 1 << " \n"[x == ans.back()];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}