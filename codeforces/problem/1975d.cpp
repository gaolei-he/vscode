#include <bits/stdc++.h>

using i64 = long long;
using pii = std::pair<int, int>;

void solve() {
    int n, a, b;
    std::cin >> n >> a >> b;
    a--, b--;
    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<std::vector<int>> dist(3);

    auto dijkstra = [&](int root, int idx) -> void {
        dist[idx].assign(n, INT_MAX);
        std::vector<char> vis(n, 0);
        std::queue<pii> q;
        std::priority_queue<pii> pq;
        pq.push({0, root});
        dist[idx][root] = 0;
        while (pq.size()) {
            auto t = pq.top();
            pq.pop();
            int ver = t.second, dis = t.first;
            if (vis[ver]) {
                continue;
            }
            vis[ver] = 1;
            for (auto x : g[ver]) {
                if (!vis[x] and dist[idx][x] > dist[idx][ver] + dis) {
                    dist[idx][x] = dist[idx][ver] + 1;
                    pq.push({dist[idx][ver] + dis, x});
                }
            }
        }
    };

    int ans = 0;

    dijkstra(a, 0);
    dijkstra(b, 1);
    // std::cerr << dist[0][b] << "\n";
    // exit(0);
    int r = -1;
    if (dist[0][b] % 2 == 0) {
        int mi = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (dist[0][i] == dist[1][i] and mi > dist[0][i]) {
                mi = dist[0][i];
                r = i;
            }
        }
        ans = mi;
    } else {
        int mi = INT_MAX;
        for (int i = 0; i < n; i++) {
            if(dist[0][i] + 1 == dist[1][i] and mi > dist[0][i]) {
                mi = dist[0][i] + 1;
                r = i;
            }
        }
        ans = mi;
    }
    // std::cerr << r << "\n";
    // exit(0);
    dijkstra(r, 2);
    // std::cerr << r1 << " " << r2 << "\n";
    // exit(0);
    int ma = 0;
    for (int i = 0; i < n; i++) {
        ma = std::max(dist[2][i], ma);
    }
    // std::cerr << ma1 << " " << ma2 << "\n";
    ans += 2 * (n - 1) - ma;

    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}