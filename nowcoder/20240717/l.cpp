#include <bits/stdc++.h>
#define int long long
using pii = std::pair<int, int>;
void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::unordered_set<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    std::vector<int> low(n + 1), dfn(n + 1), fa(n + 1);
    int cnt = 0;
    std::vector<pii> rec;
    std::function<void(int, int)> dfs = [&](int u, int f) -> void {
        fa[u] = f;
        low[u] = dfn[u] = ++cnt;
        for (auto it : g[u]) {
            if (!dfn[it]) {
                dfs(it, u);
                low[u] = std::min(low[u], low[it]);
                if (low[it] > dfn[u]) {
                    rec.emplace_back(u, it);
                }
            } else if (dfn[it] < dfn[u] && it != fa[u]) {
                low[u] = std::min(low[u], dfn[it]);
            }
        }
    };
    dfs(1, -1);
    for (auto [u, v] : rec) {
        g[u].erase(v);
        g[v].erase(u);
    }

    std::vector<int> p(n + 1), sz(n + 1, 1);
    std::iota(p.begin(), p.end(), 0);
    std::function<int(int)> find = [&](int x) {
        if (x != p[x]) {
            return p[x] = find(p[x]);
        } else {
            return p[x];
        }
    };
    for (int i = 1; i <= n; i++) {
        for (auto x : g[i]) {
            int u = find(i), v = find(x);
            if (u != v) {
                p[u]= v;
                sz[v] += sz[u];
            }
        }
    }
    std::unordered_set<int> st;
    for(int i=1;i<=n;i++) {
        st.insert(find(i));
    }
    std::vector<int> vec;
    for(auto x : st) {
        vec.push_back(sz[x]);
        // std::cerr << sz[x] << " ";
    }

    std::map<int, int> recd;
    int sm = 0;
    for (auto x : vec) {
        recd[x] += 1;
        sm += x;
    }
    recd[1] += n - sm;
    std::vector<int> dp(n + 1);
    std::vector<int> store;
    store.push_back(0);
    cnt = 0;
    for (auto &[k, v] : recd) {
        int tmp = v;
        for (int j = 0; j < 22; j++) {
            int t = (1ll << j);
            if (tmp >= t) {
                tmp -= t;
            }
            else {
                t = tmp;
                tmp = 0;
            }
            cnt++;
            store.push_back(t * k);
            if (!tmp) break;
        }
    }
    if (store.size() >= 2) {
        for (int i = store[1]; i <= n / 2; i++) {
            dp[i] = store[1];
        }
    }
    for (int i = 2; i <= cnt; i++) {
        for (int j = n / 2; j >= store[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - store[i]] + store[i]);
        }
    }
    std::cout << dp[n / 2] * (n - dp[n / 2]);

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    solve();

    return 0;
}
