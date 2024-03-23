#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> g(n);
    for(int i=1;i<n;i++) {
        int u, v;
        std::cin >> u >> v;
        u --, v --;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l = 1, r = n / (k + 1);
    std::vector<bool> vis;
    std::vector<int> sons;
    int cnt;
    std::function<void(int, int)> dfs = [&](int ver, int mid) {
        vis[ver] = true;
        sons[ver] = 1;
        for(auto x : g[ver]) {
            if(!vis[x]) {
                dfs(x, mid);
                if(sons[x] >= mid and cnt < k) {
                    sons[x] = 0;
                    cnt += 1;
                }
                sons[ver] += sons[x];
            }
        }
    };
    auto check = [&](int mid) {
        vis.assign(n, false);
        sons.assign(n, 0);
        cnt = 0;
        dfs(0, mid);
        if(cnt >= k and sons[0] >= mid) {
            return true;
        }
        return false;
    };
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    std::cout << l << "\n";
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}